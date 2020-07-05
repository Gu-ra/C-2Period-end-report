#include <Windows.h> 
#include <stdio.h>
#include <string>
#define CHARBUFF 124

void getCurrentDirectory(char* currentDirectory) {//現在のディレクトリ取得
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}
int readInt(const char* section, const char* keyword, int defaultValue, const char* flePath) {
	return GetPrivateProfileInt(section, keyword, defaultValue, flePath);
}
bool readChar(const char* section, const char* keyword, const char* defaultValue, char* returnValue, const char* flePath) {
	return GetPrivateProfileString(section, keyword, defaultValue, returnValue, CHARBUFF, flePath);
}
double readDouble(const char* section, const char* keyword, double defaultValue, const char* flePath) {
	char deft[CHARBUFF];
	sprintf_s(deft,"%f",defaultValue);
	char res[CHARBUFF];
	double re;
	if (readChar(section, keyword, deft, res, flePath)) {
		re = strtod(res,NULL);
	}
	else {
		re = defaultValue;
	}
	return re;
}
bool writeInt(const char* section, const char* keyword, int returnValue, const char* flePath) {
	char res[CHARBUFF];
	sprintf_s(res,"%d",returnValue);
	if (WritePrivateProfileString(section, keyword, res, flePath)) {
		return true;
	}
	else {
		fprintf_s(stderr, "failed to write\n");
		return false;
	}
}
bool writeChar(const char* section, const char* keyword, const char* returnValue, const char* flePath) {
	if (WritePrivateProfileString(section, keyword, returnValue, flePath)) {
		return true;
	}
	else {
		fprintf_s(stderr, "failed to write\n");
		return false;
	}
}
bool writeDouble(const char* section, const char* keyword, double returnValue, const char* flePath) {
	char res[CHARBUFF];
	sprintf_s(res, "%f", returnValue);
	if (WritePrivateProfileString(section, keyword, res, flePath)) {
		return true;
	}
	else {
		fprintf_s(stderr, "failed to write\n");
		return false;
	}
}
