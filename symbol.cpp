#include "stdafx.h"
#include "symbol.h"

using namespace std;

symbol::symbol(){
	ascii_num = 0;
}

symbol::symbol(int M){
	if (M >= 0)
		ascii_num = M;
	else ascii_num = 256 + M;
}

int symbol::get_ascii(){
	return this->ascii_num;
}

void symbol::set_symbol(int M){
	this->ascii_num = M;
}

symbol::~symbol(){}
