#include "M_Game.h"
/*class KeyBoard*/
int Keyboard::keyActivity(){
	SDL_Event event;
	if (SDL_PollEvent(&event)){
		if ((event.type == SDL_QUIT) || (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE))//�I���C�x���g
			return 0;
		if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE)
			keyEvent = true;
	}
	return 1;
}
/*class Assets*/
int Assets::scroll(){
	static int scroll;
	if (scroll == 640)
		scroll = 0;
	return scroll++;
}
void Assets::hitCheck(){
	for (int i = 0; i < 2; i++){
		if ((ledybug.posX < (obstacle[i].posX + obstacle[i].width)) &&
			(obstacle[i].posX < (ledybug.posX + ledybug.width)) &&
			(ledybug.posY < (obstacle[i].posY_U + obstacle[i].height)) &&
			(obstacle[i].posY_U < (ledybug.posY + ledybug.height)))
			ledybug.alive = false;

		if ((ledybug.posX < (obstacle[i].posX + obstacle[i].width)) &&
			(obstacle[i].posX < (ledybug.posX + ledybug.width)) &&
			(ledybug.posY < (obstacle[i].posY_T + obstacle[i].height)) &&
			(obstacle[i].posY_T < (ledybug.posY + ledybug.height)))
			ledybug.alive = false;
	}
}
/*class Game*/
Uint32 Game::delayTime(){
	static Uint32 prev_time = SDL_GetTicks();
	static Uint32 tick_interval = 1000 / 30;
	Uint32 now = SDL_GetTicks();
	short int delay_time = tick_interval - (now - prev_time);
	prev_time = now + delay_time;

	if (delay_time > 0)
		return delay_time;
	else
		return 0;
}
void Game::update(){
	if (gameMode == 0 && keyboard.keyEvent == true){//�^�C�g����ʂŃX�y�[�X�������ꂽ��Q�[�����J�n����
		gameMode = 1; keyboard.keyEvent = false;
	}

	else if (gameMode == 1){
			assets.hitCheck();
		if (keyboard.keyEvent == true){//�Q�[�����ɃX�y�[�X�L�[�������ꂽ��W�����v����
			assets.ledybug.jump(); keyboard.keyEvent = false;
		}
		else if (keyboard.keyEvent == false)
			assets.ledybug.fall();//����
		if (assets.ledybug.alive == false){
			assets.hitSE.play(-1);
			gameMode = 2;
		}
	}

	else if (gameMode == 2 && keyboard.keyEvent == true){//�Q�[���I�[�o�[��ʂŃX�y�[�X�������ꂽ��Q�[�����J�n����
		gameMode = 0; keyboard.keyEvent = false;
		fulag = false;
		assets.ledybug.reset(); 
		for (int i = 0; i < 2; i++){
			assets.obstacle[i].reset();
		}
	}
}
void Game::draw(){
	assets.background.create(*screen, 0, 0, 1280, 360, -assets.scroll(), 0);//�w�i�̕\��

	switch (gameMode){
	case 0://�^�C�g�����
		assets.ledybug.create(*screen, 0, 0, assets.ledybug.width, assets.ledybug.height, assets.ledybug.posX, assets.ledybug.posY);//���@�̕`��
		assets.title.create(*screen, 0, 0, 600, 200, 20, 80);//�^�C�g���̕`��
		break;

	case 1://�Q�[�����
		assets.ledybug.create(*screen, 0, 0, 40, 24, assets.ledybug.posX, assets.ledybug.posY);
		assets.obstacle[0].create(*screen, true, 0);
		assets.obstacle[1].create(*screen, [&](Sint16 posX)->bool{//�O�̃I�u�W�F�N�g���x��Đ�������
			if (posX < 280 && fulag == false){
				fulag = true; return fulag;
			}
			return fulag;
		}(assets.obstacle[0].posX), 1);
		break;

	case 2://�Q�[���I�[�o�[���
		assets.gameOver.create(*screen, 0, 0, 600, 200, 20, 80);//�Q�[���I�[�o�[��ʂ̕`��
		break;
	}
	SDL_UpdateRect(screen, 0, 0, 0, 0);//��ʂ̍X�V
}
void Game::initialize(){
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0)//SDL�̏�����
		throw "SDL_INITIALIZATION_ERROR";
	SDL_WM_SetCaption("flappy ladybug", NULL);//�^�C�g���ƃA�C�R��
	screen = SDL_SetVideoMode(640, 360, 32, SDL_DOUBLEBUF | SDL_HWSURFACE);//�_�u���o�b�t�@�����O �r�f�I���������g�p����
	if (screen == NULL)
		throw"SURFACE_IS_LOAD_ERROR";

	assets.background.load("./assets/buckground.png");//�w�i�̃��[�h
	assets.ledybug.load("./assets/ledybug.png");//���@�̃��[�h
	assets.title.load("./assets/flappyLadyBug.png");//�^�C�g���̃��[�h
	assets.gameOver.load("./assets/gameOver.png");//�Q�[���I�[�o�[�摜�̃��[�h
	assets.obstacle[0].load();
	assets.obstacle[1].load();
	assets.hitSE.load("./assets/ledybugSound.wav");
}
void Game::mainLoop(){
	while (keyboard.keyActivity() != 0){
		update();
		std::thread th(&Game::draw, this);//�ʃX���b�h�ŕ`�悷��
		th.join();//th�̏������I���܂őҋ@����
		SDL_Delay(delayTime());
	}
}
void Game::finalize(void){
	SDL_FreeSurface(assets.background.image);
	SDL_FreeSurface(assets.ledybug.image);
	SDL_FreeSurface(assets.title.image);
	SDL_FreeSurface(assets.gameOver.image);
	SDL_Quit();
}