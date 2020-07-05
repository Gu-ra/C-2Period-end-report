#ifndef INCLUDED_Setting_h_
#define INCLUDED_Setting_h_
void getCurrentDirectory(char* currentDirectory);
int readInt(const char* section, const char* keyword, int defaultValue, const char* flePath);
bool readChar(const char* section, const char* keyword, const char* defaultValue, char* returnValue, const char* flePath);
double readDouble(const char* section, const char* keyword, double defaultValue, const char* flePath);
bool writeInt(const char* section, const char* keyword, int returnValue, const char* flePath);
bool writeChar(const char* section, const char* keyword, const char* returnValue, const char* flePath);
bool writeDouble(const char* section, const char* keyword, double returnValue, const char* flePath);
#endif