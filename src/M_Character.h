#ifndef M_CHARACTER_H
#define M_CHARACTER_H
#include "Header.h"
#include "M_GameObjectManager.h"
/*���@*/
class Character :
	public GameObjectManager{
public:
	Uint16 width = 40; Uint16 height = 24;
	void jump();//�W�����v
	void fall();//������
	bool alive = true;//���@�������Ă邩
	Sint16 posX = 50; Sint16 posY = 168;//���@�̍���
	void reset();//������
};
#endif //M_CHARACTER_H