//класс содержащий комбинации клавиш
#include"stdafx.h"
#include"Claf.h"
#include"symbol.h"
#include <list>
#include <iterator>
#include "Derived_exception.h"

#pragma once

using namespace std;

class Data_list : public Claf{
	list<Claf> data; //stl контейнер
public:
	Data_list();//конструктор
	Data_list(const Data_list &);//деструктор
	void show_list();
	void write_file();
	void read_file();
	void add_list(Claf &);
	Claf pop_back();
	void push_front(Claf &);
	void clear_list();
	void clear_file();
	void operator=(const Data_list &);
	Data_list del_from_end(int);
	int size_of();
	list<Claf>::iterator begin();
	list<Claf>::iterator end();
	//	void del_list();
	Claf top_front(int);
};