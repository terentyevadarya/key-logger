// ����� ���������� ��� ������� 

#include"stdafx.h"
#include"symbol.h"
#include <iostream>

#pragma once

using namespace std;

class Claf :public symbol{// ����������� �� symbol
protected:
	string line;
public:
	Claf();//�����������
	Claf(const Claf&);// ����������� �����������
	~Claf();

	void show_Claf();
	string get_Claf();
	void set_Claf(char *, int);
	void write_b(fstream& file);// ������ � ����
	void read_b(fstream&);// ������ �� �����
	friend ostream &operator<<(ostream &, Claf);//���������� ������

	int operator>(int);
	int operator<(int);
	int operator==(int);
	int operator!=(int);

	int operator>(Claf &);
	int operator<(Claf &);
	int operator==(Claf &);
	int operator!=(Claf &);



	void set_symbol(char);
};