#include "M_Obstacle.h"
/*class Obstacle*/
void Obstacle::update(int index){
	static Sint16 range[2];
	if (posX < (-75)){ //Á‚¦‚½‚çV‚µ‚­áŠQ•¨‚ð¶¬‚·‚é
		posX = 640;

		srand(time(NULL)); range[index] = rand() % 100 + 1;//{//áŠQ•¨‚Ì¶¬Žž‚Éƒ‰ƒ“ƒ_ƒ€‚Å‚‚³‚ðÝ’è‚·‚é
		if (range[index] % 2 == 1)
			range[index] = (-range[index]);
	}

	posY_U = 210 + range[index]; posY_T = (-160) + range[index];
	posX -= 6;
}
void Obstacle::load(){
	under.load("./assets/obstacleUnder.png");
	top.load("./assets/obstacleTop.png");
}
void Obstacle::create(SDL_Surface &screen, bool fulag, int index){
	if (fulag == true){
		update(index);
		under.create(screen, 0, 0, width, height, posX, posY_U);
		top.create(screen, 0, 0, width, height, posX, posY_T);
	}
}
void Obstacle::reset(){
	posX = 640; posY_U = 210; posY_T = (-160);
}