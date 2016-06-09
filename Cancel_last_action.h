#pragma once
#include "Data_list.h"
#include <stack>

//����� ������ ��������

using namespace std;

class Last_action{
	stack<int> int_st; //���� ���������� ������� ���������� ��������
	stack<Data_list> line_st; //����, ������� ���������� ���������� ������
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