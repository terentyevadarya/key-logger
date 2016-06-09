#pragma once
#include "My_Exception.h"
class Cont_Ex : public My_Exception
{
private:
	char* error_name;
public:
	friend ostream & operator << (ostream &, Cont_Ex &);
	Cont_Ex(int);
	Cont_Ex(int, char*);
	Cont_Ex(const Cont_Ex &);
	~Cont_Ex();
};
