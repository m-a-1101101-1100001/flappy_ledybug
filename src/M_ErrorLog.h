#ifndef ERRORLOG_H
#define ERRORLOG_H
#include "Header.h"
#include "M_FileIO.h"
/*�G���[���O���o�͂���G���[�̓��e��throw�ɋL�q*/
class ErrorLog :
	public FileIO{
private:
	const char *e;//�G���[�R�[�h

public:
	ErrorLog(const char *e, const char *file = "error.txt");
	void write();//�G���[���O���t�@�C���ɏo�͂���
};
#endif //ERRORLOG_H