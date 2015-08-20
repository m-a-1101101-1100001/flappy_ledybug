#include "M_Character.h"
void Character::jump(){
	Sint16 jumpH = 30;//ˆê‰ñ‚ÅƒWƒƒƒ“ƒv‚·‚é‚‚³

	if ((posY - jumpH) < 0)//˜g‚©‚ç‚Í‚İo‚È‚¢‚æ‚¤‚É‚·‚é
		jumpH= 0;
	posY -= jumpH;
}
void Character::fall(){
	Sint16 fallH = 5;//—‚¿‚é‘¬‚³
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