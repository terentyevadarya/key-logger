// класс содержащий имя клавиши 

#include"stdafx.h"
#include"symbol.h"
#include <iostream>

#pragma once

using namespace std;

class Claf :public symbol{// наследуется от symbol
protected:
	string line;
public:
	Claf();//конструктор
	Claf(const Claf&);// конструктор копирования
	~Claf();

	void show_Claf();
	string get_Claf();
	void set_Claf(char *, int);
	void write_b(fstream& file);// запись в файл
	void read_b(fstream&);// чтение из файла
	friend ostream &operator<<(ostream &, Claf);//перегрузка вывода

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