#include "stdafx.h"

#pragma once
using namespace std;

class symbol  {
protected:
	int ascii_num;
public:
	symbol();
	symbol(int M);
	void set_symbol(int);
	virtual ~symbol() = 0;
	int get_ascii();
};