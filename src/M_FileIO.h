#ifndef M_FILEIO_H
#define M_FILEIO_H
#include "Header.h"
class FileIO {
protected:
	FILE *fp;
	const char *file = NULL;
	virtual void checkFile();//�t�@�C���̗L���B���݂��Ȃ��ꍇ�����I�ɏI������

public:
	FileIO(const char *file);//�t�@�C���̃p�X�w��
	const char* readAssets();//�t�@�C���p�X�̓ǂݍ���
	void write(const char *str);//�t�@�C���̏�������
};
#endif //M_FILEIO_H