#include "M_Character.h"
void Character::jump(){
	Sint16 jumpH = 30;//���ŃW�����v���鍂��

	if ((posY - jumpH) < 0)//�g����͂ݏo�Ȃ��悤�ɂ���
		jumpH= 0;
	posY -= jumpH;
}
void Character::fall(){
	Sint16 fallH = 5;//�����鑬��
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