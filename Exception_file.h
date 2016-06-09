#pragma once
#include "My_Exception.h"
class File_Ex : public My_Exception
{
private:
	char* error_name;
public:
	friend ostream & operator << (ostream &, File_Ex &);
	File_Ex(int);
	File_Ex(int, char*);
	File_Ex(const File_Ex &);
	~File_Ex();
};
