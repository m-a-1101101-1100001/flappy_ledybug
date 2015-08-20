#include "M_ErrorLog.h"
ErrorLog::ErrorLog(const char *e, const char *file ):FileIO(file){
	this->e = e;
	this->file = file;
}

void ErrorLog::write(){
	try{
		FileIO::write(e);
	}
	catch (const char){//�G���[���O�̏������݂Ɏ��s�����ꍇ�����I������
		SDL_Quit();
	}
}