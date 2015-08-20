#include "M_ErrorLog.h"
ErrorLog::ErrorLog(const char *e, const char *file ):FileIO(file){
	this->e = e;
	this->file = file;
}

void ErrorLog::write(){
	try{
		FileIO::write(e);
	}
	catch (const char){//エラーログの書き込みに失敗した場合強制終了する
		SDL_Quit();
	}
}