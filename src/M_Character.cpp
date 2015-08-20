#include "M_Character.h"
void Character::jump(){
	Sint16 jumpH = 30;//一回でジャンプする高さ

	if ((posY - jumpH) < 0)//枠からはみ出ないようにする
		jumpH= 0;
	posY -= jumpH;
}
void Character::fall(){
	Sint16 fallH = 5;//落ちる速さ
	if ((posY + fallH) > 340){
		fallH = 0;
		alive = false;
	}
	posY += fallH;
}
void Character::reset(){
	posY = 168;
	alive = true;
}