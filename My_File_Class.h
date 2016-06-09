#include "stdafx.h"
#pragma once


class FileClass
{
protected:
	char* file_name;
public:
	FileClass(const char*);
	~FileClass();
};


FileClass::FileClass(const char* st)
{
	file_name = new char[strlen(st) + 1];
	strcpy(file_name, st);
}


FileClass::~FileClass()
{
}

