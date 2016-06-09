#pragma once
#include "My_Exception.h"
class Derived_Exception : public My_Exception
{
private:
	char *error_name;
public:
	friend ostream & operator << (ostream &, Derived_Exception &);
	Derived_Exception();
	Derived_Exception(int, char*);
	Derived_Exception(const Derived_Exception &);
	~Derived_Exception();
	friend int enter_INT(int, int);
	friend int enter_INT();
	friend int check_INT(int, int,int);
	friend int check_NULL(int);
};
