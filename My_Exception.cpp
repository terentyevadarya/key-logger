#include "My_Exception.h"

My_Exception::My_Exception()
{
	error_code = 0;
}

My_Exception::My_Exception(int i)
{
	error_code = i;
}

My_Exception::~My_Exception(){}


