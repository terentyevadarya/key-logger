#pragma once
#include"stdafx.h"
#include "Data_list.h"
#include<list>
#include <iterator>


using namespace std;

void Data_list::show_list(){
	//�������� �� ������
	list<Claf>::iterator iter = this->data.begin();
	Claf T;
	int i = 0;//������ �� �������
	//���� �� ����� �� �����
	while (iter != data.end()){
		T = *iter;
		T.show_Claf();//������� �� ������ ����������
		iter++;//��������� �� ���� �������
		i++;
	}
	try {
		if (i == 0) //���� ������ �������
			throw Derived_Exception(7, "���� ����!");
	}
	catch (Derived_Exception &ex)
	{
		cout << ex;
		return;
	}
	//this->clear_list();
}

//������ � ����
void Data_list::write_file()
{
	fstream file;
	file.open("Data_list_buf.dat", ios_base::app |
		ios_base::binary);
	file.seekg(0);
	list<Claf>::iterator iter = this->data.begin();//�������� �� ������
	Claf T;
	while (iter != data.end()){//���� �� ����� �������
		T = *iter;
		iter++;
		T.write_b(file);
	}
	//cout << "���� Data_list_buf.dat �����������" << endl;
	file.close();

}

//������ �� ��������� �����
void Data_list::read_file()
{
	fstream file;	
	file.open("Data_list_buf.dat", ios_base::in | ios_base::binary);
	Claf obj;
	this->clear_list();//������� �������
	while (1){
		obj.read_b(file);
		if (file.eof())
			break;
		this->data.push_back(obj);//���������� ������ �� �����
	}	
	//cout << "���� Data_list_buf.dat ��������" << endl;
}

void Data_list::clear_file(){
	fstream file;
	file.open("Data_list_buf.dat", ios_base::out | ios_base::binary);
	file.close();
}
//��������� ������ � ����
void Data_list::add_list(Claf &x){
	this->data.push_back(x);
}
//��������� ��������� �� ������
list<Claf>::iterator Data_list::begin(){
	list<Claf>::iterator iter = this->data.begin();
	return iter;
}

list<Claf>::iterator Data_list::end(){
	list<Claf>::iterator iter = this->data.end();
	return iter;
}
//������� �������
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
	for (i = 0; i < num; i++){//���� �� ������ ������������ �����
		this->data.pop_back();//�������
	}
	return *this;
}

//���������� ������ �������
int Data_list::size_of(){
	return this->data.size();
}

//�������� ��������� ������� �������
Claf Data_list::pop_back(){
	Claf obj;
	obj = this->data.back();
	this->data.pop_back();//� ������� ���
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
		if (i == x) return T;//���� ������ ������ � ��������� ���������
		iter++;
		i++;
	}
	return Z;
}