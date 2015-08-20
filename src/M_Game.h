#ifndef M_GAME_H
#define M_GAME_H
#include "Header.h"
#include "M_GameObjectManager.h"
#include "M_Character.h"
#include "M_Obstacle.h"
#include "M_Sound.h"
#include "Game.h"
/*�Q�[���Ŏg���A�Z�b�g*/
class Assets{
public:
	GameObjectManager background; //�w�i
	int scroll();//1�t���[���ŃX�N���[�������钷��
	GameObjectManager title;//�^�C�g��
	GameObjectManager gameOver;//�Q�[���I�[�o�[
	Character ledybug;//���@(ledybug)
	Obstacle obstacle[2];//��Q��
	void hitCheck();//�����蔻��
	Sound hitSE;
};
/*�L�[�{�[�h�̓��͂����������ǂ������f����N���X
�C�x���g������������keyEvent��false�ɖ߂�
*/
class Keyboard{
public:
	bool keyEvent = false;//�L�[���̓C�x���g�����������ǂ����B�C�x���g������������false�ɖ߂�
	int keyActivity();//�L�[�C�x���g
};
/*�Q�[�������ۂɓ������N���X*/
class Game:
	public InterfaceGame  {
private:
	SDL_Surface *screen;//���C�����
	Assets assets;
	Keyboard keyboard;
	int gameMode = 0;//�Q�[���̃X�N���[����ς��邽�߂̕ϐ�(�O�^�C�g���A1�Q�[���A2�Q�[���I�[�o�[)
	virtual Uint32 delayTime();//�t���[�����[�g�̍œK��(fps30)
	bool fulag = false;//���؏������K�v��
	virtual void update();
	virtual void draw();

public:
	virtual void initialize();//��O���ł�悤�ɂ��Ă���
	virtual void mainLoop();
	virtual void finalize();
};
#endif //M_GAME_H