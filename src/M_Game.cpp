#include "M_Game.h"
/*class KeyBoard*/
int Keyboard::keyActivity(){
	SDL_Event event;
	if (SDL_PollEvent(&event)){
		if ((event.type == SDL_QUIT) || (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE))//終了イベント
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
	if (gameMode == 0 && keyboard.keyEvent == true){//タイトル画面でスペースが押されたらゲームを開始する
		gameMode = 1; keyboard.keyEvent = false;
	}

	else if (gameMode == 1){
			assets.hitCheck();
		if (keyboard.keyEvent == true){//ゲーム中にスペースキーが押されたらジャンプする
			assets.ledybug.jump(); keyboard.keyEvent = false;
		}
		else if (keyboard.keyEvent == false)
			assets.ledybug.fall();//落下
		if (assets.ledybug.alive == false){
			assets.hitSE.play(-1);
			gameMode = 2;
		}
	}

	else if (gameMode == 2 && keyboard.keyEvent == true){//ゲームオーバー画面でスペースが押されたらゲームを開始する
		gameMode = 0; keyboard.keyEvent = false;
		fulag = false;
		assets.ledybug.reset(); 
		for (int i = 0; i < 2; i++){
			assets.obstacle[i].reset();
		}
	}
}
void Game::draw(){
	assets.background.create(*screen, 0, 0, 1280, 360, -assets.scroll(), 0);//背景の表示

	switch (gameMode){
	case 0://タイトル画面
		assets.ledybug.create(*screen, 0, 0, assets.ledybug.width, assets.ledybug.height, assets.ledybug.posX, assets.ledybug.posY);//実機の描画
		assets.title.create(*screen, 0, 0, 600, 200, 20, 80);//タイトルの描画
		break;

	case 1://ゲーム画面
		assets.ledybug.create(*screen, 0, 0, 40, 24, assets.ledybug.posX, assets.ledybug.posY);
		assets.obstacle[0].create(*screen, true, 0);
		assets.obstacle[1].create(*screen, [&](Sint16 posX)->bool{//前のオブジェクトより遅れて生成する
			if (posX < 280 && fulag == false){
				fulag = true; return fulag;
			}
			return fulag;
		}(assets.obstacle[0].posX), 1);
		break;

	case 2://ゲームオーバー画面
		assets.gameOver.create(*screen, 0, 0, 600, 200, 20, 80);//ゲームオーバー画面の描画
		break;
	}
	SDL_UpdateRect(screen, 0, 0, 0, 0);//画面の更新
}
void Game::initialize(){
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0)//SDLの初期化
		throw "SDL_INITIALIZATION_ERROR";
	SDL_WM_SetCaption("flappy ladybug", NULL);//タイトルとアイコン
	screen = SDL_SetVideoMode(640, 360, 32, SDL_DOUBLEBUF | SDL_HWSURFACE);//ダブルバッファリング ビデオメモリを使用する
	if (screen == NULL)
		throw"SURFACE_IS_LOAD_ERROR";

	assets.background.load("./assets/buckground.png");//背景のロード
	assets.ledybug.load("./assets/ledybug.png");//実機のロード
	assets.title.load("./assets/flappyLadyBug.png");//タイトルのロード
	assets.gameOver.load("./assets/gameOver.png");//ゲームオーバー画像のロード
	assets.obstacle[0].load();
	assets.obstacle[1].load();
	assets.hitSE.load("./assets/ledybugSound.wav");
}
void Game::mainLoop(){
	while (keyboard.keyActivity() != 0){
		update();
		std::thread th(&Game::draw, this);//別スレッドで描画する
		th.join();//thの処理が終わるまで待機する
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