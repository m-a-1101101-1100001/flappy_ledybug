#include "M_FileIO.h"

FileIO::FileIO(const char *file){
	this->file = file;
}
void FileIO::checkFile(){
	if ((fopen_s(&fp, file, "r")) != NULL)
		throw "FILE_IS_NOT_FOUND";
	fclose(fp);
}
const char* FileIO::readAssets(){
	checkFile();
	return file;
}
void FileIO::write(const char *str){
	if (fopen_s(&fp, file, "w") != NULL)
		throw "FILE_IS_NOT_OPEND";
	fputs(str, fp);
	fclose(fp);
}