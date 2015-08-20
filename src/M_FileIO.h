#ifndef M_FILEIO_H
#define M_FILEIO_H
#include "Header.h"
class FileIO {
protected:
	FILE *fp;
	const char *file = NULL;
	virtual void checkFile();//ファイルの有無。存在しない場合強制的に終了する

public:
	FileIO(const char *file);//ファイルのパス指定
	const char* readAssets();//ファイルパスの読み込み
	void write(const char *str);//ファイルの書き込み
};
#endif //M_FILEIO_H