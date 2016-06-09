#pragma once
#include"stdafx.h"
#include "Data_list.h"
#include<list>
#include <iterator>


using namespace std;

void Data_list::show_list(){
	//итератор на начало
	list<Claf>::iterator iter = this->data.begin();
	Claf T;
	int i = 0;//флажок на пустоту
	//пока не дошли до конца
	while (iter != data.end()){
		T = *iter;
		T.show_Claf();//выводим на печать содержимое
		iter++;//переходим на след элемент
		i++;
	}
	try {
		if (i == 0) //если пустой выходим
			throw Derived_Exception(7, "Файл пуст!");
	}
	catch (Derived_Exception &ex)
	{
		cout << ex;
		return;
	}
	//this->clear_list();
}

//запись в файл
void Data_list::write_file()
{
	fstream file;
	file.open("Data_list_buf.dat", ios_base::app |
		ios_base::binary);
	file.seekg(0);
	list<Claf>::iterator iter = this->data.begin();//итератор на начало
	Claf T;
	while (iter != data.end()){//пока не конец очереди
		T = *iter;
		iter++;
		T.write_b(file);
	}
	//cout << "Файл Data_list_buf.dat перезаписан" << endl;
	file.close();

}

//чтение из буферного файла
void Data_list::read_file()
{
	fstream file;	
	file.open("Data_list_buf.dat", ios_base::in | ios_base::binary);
	Claf obj;
	this->clear_list();//очищаем очередь
	while (1){
		obj.read_b(file);
		if (file.eof())
			break;
		this->data.push_back(obj);//записываем данные из файла
	}	
	//cout << "Файл Data_list_buf.dat прочитан" << endl;
}

void Data_list::clear_file(){
	fstream file;
	file.open("Data_list_buf.dat", ios_base::out | ios_base::binary);
	file.close();
}
//добавляем данные в лист
void Data_list::add_list(Claf &x){
	this->data.push_back(x);
}
//установка итератора на начало
list<Claf>::iterator Data_list::begin(){
	list<Claf>::iterator iter = this->data.begin();
	return iter;
}

list<Claf>::iterator Data_list::end(){
	list<Claf>::iterator iter = this->data.end();
	return iter;
}
//очистка очереди
void Data_list::clear_list(){
	this->data.clear();
}

void Data_list::operator=(const Data_list &obj){
	this->data = obj.data;
}

Data_list::Data_list(const Data_list &obj){
	//cout << "copy" << endl;
	this->data = obj.data;
}

Data_list::Data_list(){
}


Data_list Data_list::del_from_end(int num){
	int i = 0;
	for (i = 0; i < num; i++){//пока не больше необходимого числа
		this->data.pop_back();//удаляем
	}
	return *this;
}

//возвращаем размер очереди
int Data_list::size_of(){
	return this->data.size();
}

//получаем последний элемент очереди
Claf Data_list::pop_back(){
	Claf obj;
	obj = this->data.back();
	this->data.pop_back();//и удаляем его
	return obj;
}

void Data_list::push_front(Claf &obj){
	this->data.push_front(obj);
}


Claf Data_list::top_front(int x){
	list<Claf>::iterator iter = this->data.begin();
	Claf T,Z;
	int i = 0;
	while (iter != data.end()){
		T = *iter;
		if (i == x) return T;//если индекс совпал с введенным возвратим
		iter++;
		i++;
	}
	return Z;
}