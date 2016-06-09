#pragma once
#include "stdafx.h"
#include "Cancel_last_action.h"
#include <iterator>

void Last_action::push(Data_list &obj, int i){
	//заносим в стек новую комбинацию клавиш
	this->int_st.push(i); 
	//заносим в стек признак последнего действия
	this->line_st.push(obj);

}


Last_action::~Last_action(){}

Last_action::Last_action(){}

int Last_action::pop_int(){
	int ch;
	//получаем признак последнего действия
	ch = this->int_st.top();//вынимаем из стека
	this->int_st.pop();
	return ch;//возвращем значение
}

//вынимаем из стека последнюю комбинацию клавиш
Data_list Last_action::pop_line(){
	Data_list cur;
	if (this->line_st.empty()) { cout << "error"; return cur; }
	cur = this->line_st.top();
	this->line_st.pop();//возвращаем ее
	return cur;
}

//конструктор копирования
Last_action::Last_action(const Last_action&obj){
	this->int_st = obj.int_st;
	this->line_st = obj.line_st;
}


void Last_action::operator=(Last_action &obj){
	this->int_st = obj.int_st;
	this->line_st = obj.line_st;
}

//проверка на пустоту
int Last_action::is_empty(){
	if (this->int_st.empty()) return 1;
	return 0;
}