#ifndef M_CHARACTER_H
#define M_CHARACTER_H
#include "Header.h"
#include "M_GameObjectManager.h"
/*実機*/
class Character :
	public GameObjectManager{
public:
	Uint16 width = 40; Uint16 height = 24;
	void jump();//ジャンプ
	void fall();//落ちる
	bool alive = true;//実機が生きてるか
	Sint16 posX = 50; Sint16 posY = 168;//実機の高さ
	void reset();//初期化
};
#endif //M_CHARACTER_H