#ifndef M_OBSTACLE_H
#define M_OBSTACLE_H
#include "M_GameObjectManager.h"
/*障害物*/
class Obstacle:
	public GameObjectManager{
private:
	GameObjectManager under; GameObjectManager top;
	void update(int index);//障害物をアニメーションさせる

public:
	Sint16 posX = 640; Sint16 posY_U = 210; Sint16 posY_T = (-160);//実際の座標
	Uint16 width = 75; Uint16 height = 300;
	void load();
	void create(SDL_Surface &screen, bool fulag, int index);
	void reset();
};
#endif //M_OBSTACLE_H