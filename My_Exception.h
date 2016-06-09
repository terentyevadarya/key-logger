#pragma once
#include <iostream>

using namespace std;

class My_Exception
{
protected:
	int error_code;
public:
	My_Exception();
	My_Exception(int);
	~My_Exception();
};
