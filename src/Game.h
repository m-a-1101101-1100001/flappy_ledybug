#ifndef GAME_H
#define GAME_H
/*�Q�[���̋@�\���܂Ƃ߂�*/
class InterfaceGame{

	virtual void update() = 0;//�Q�[���̏�Ԃ��X�V����
	virtual void draw() = 0;//�`�悷��
	virtual void initialize() = 0;//����������
	virtual void mainLoop() = 0;//���C�����[�v
	virtual void finalize() = 0;//�I������

};
#endif //GAME_H