#ifndef ERRORLOG_H
#define ERRORLOG_H
#include "Header.h"
#include "M_FileIO.h"
/*エラーログを出力するエラーの内容はthrowに記述*/
class ErrorLog :
	public FileIO{
private:
	const char *e;//エラーコード

public:
	ErrorLog(const char *e, const char *file = "error.txt");
	void write();//エラーログをファイルに出力する
};
#endif //ERRORLOG_H