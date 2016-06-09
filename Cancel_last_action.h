#pragma once
#include "Data_list.h"
#include <stack>

//класс отмены действий

using namespace std;

class Last_action{
	stack<int> int_st; //стек содержащий признак последнего действия
	stack<Data_list> line_st; //стек, который содержащит комбинации клавиш
public:
	Last_action();
	~Last_action();
	Last_action(const Last_action&);
	void operator=(Last_action &);
	void push(Data_list &, int);	
	int pop_int();
	Data_list pop_line();	
	int is_empty();
};