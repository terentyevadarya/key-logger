#pragma once
#include "stdafx.h"
#include "Cancel_last_action.h"
#include "My_File_Class.h"
#include <list>
#include <iterator>
#include "Derived_exception.h"

class BinaryFileClass : public FileClass
{
private:
	fstream file;
public:
	Data_list& read_all(Data_list&);
	void add_new_elements(Data_list&, int, Last_action &);
	void write_file_buf(Data_list&);
	void open_file(int);
	void cancel(Last_action &);
	int is_empty();
	BinaryFileClass(char const*);
	~BinaryFileClass();
	void add_to_end(Data_list&);
	void del_elements(Last_action&, int);
};

void BinaryFileClass::del_elements(Last_action &stek, int num)
{
	Claf obj;
	Data_list buf, buf1;
	int size;
	this->read_all(buf);//���������� ���������� �� �����
	size = buf.size_of();
	try {
		if (size == 0)
			throw Derived_Exception(7, "���� ����!");

			if (size < num || num <= 0)
				throw 
				Derived_Exception
				(7, "�������� ����������,�������� �������� ������");		
	}
	//���� ������ ������� �� �������
	catch(Derived_Exception &ex)
	{
		cout << ex;
		return;
	}
	int i;
	// ������� �� ������� � ������� � ��������
	for (i = 0; i < num; i++){
		obj = buf.pop_back();
		buf1.push_front(obj);
	}
	stek.push(buf1, 0);//�������� ������� ������� � ���� ������
	this->write_file_buf(buf);

}

void BinaryFileClass::add_to_end(Data_list &b)
{
	Claf obj;
	open_file(0);//��������� ���� � ������ ��������
	is_empty();	
	list<Claf>::iterator iter = b.begin();//�������� �� ������
	while (iter != b.end()){
		obj = *iter;
		iter++;
		obj.write_b(file);// ���������� ���� �� ������� ��� �������
	}
	b.clear_list();
	//cout << "���� " << this->file_name << " �����������" << endl;
	file.close();
}


void BinaryFileClass::cancel(Last_action &stek){
	int ch,i;
	Data_list buf, cur;
	i = stek.is_empty();
	try {
		if (i==1)
		throw Derived_Exception(7, "������ ���!");
	}	
	catch (Derived_Exception &ex)
	{
		cout << ex;	
		return;
	}
	ch = stek.pop_int();//�������, ����� ���� ��������� ��������	
	this->read_all(buf);
	//���� ������� ������ ��������� ���� ����������
	if (ch == 1) {
		cur = stek.pop_line();
		buf.del_from_end(cur.size_of());//������� �� �������
		this->write_file_buf(buf);//��������������
	}
	//���� ���� �� ��������
	if (ch == 0){
		cur = stek.pop_line();
		this->add_to_end(cur);
	}
}



BinaryFileClass::BinaryFileClass(char const* st) : FileClass(st)
{
	file.close();
}

//����������
BinaryFileClass::~BinaryFileClass()
{
}

//�������� ����� � ������ �������
void BinaryFileClass::open_file(int i){
	if (i) file.open(file_name, ios_base::in | ios_base::out | ios_base::trunc
		| ios_base::binary);
	else file.open(file_name, ios_base::app | ios_base::binary);

}


int BinaryFileClass::is_empty()
{
	try
	{
		if (!file)
		throw Derived_Exception(1, file_name);
	}
	catch (Derived_Exception &ex)
	{
		cout << ex;
	}	
	return 1;
}





void BinaryFileClass::add_new_elements(Data_list &b, int i, Last_action &stek)
{
	Claf obj;
	open_file(i);
	is_empty();	
	list<Claf>::iterator iter = b.begin();
	while (iter != b.end()){
		obj = *iter;
		iter++;
		obj.write_b(file);
	}
	stek.push(b, 1);
	b.clear_list();
	//cout << "���� " << this->file_name << " �����������" << endl;
	file.close();
}

void BinaryFileClass::write_file_buf(Data_list &b)
{
	Claf obj;
	open_file(1);
	is_empty();	
	list<Claf>::iterator iter = b.begin();
	while (iter != b.end()){
		obj = *iter;
		iter++;
		obj.write_b(file);
	}
	b.clear_list();
	//cout << "���� " << this->file_name << " �����������" << endl;
	file.close();
}


//������ �� �����
Data_list& BinaryFileClass::read_all(Data_list& b)
{
	
	file.open(file_name, ios::in | ios::binary);
	is_empty();
	b.clear_list();
	Claf obj;
	while (1){
		obj.read_b(file);
		if (file.eof())//���� �� ����� �����
			break;
		b.add_list(obj);//��������� � ����
	}
	
	//cout << "���� " << this->file_name << " ��������" << endl;
	file.close();
	return b;
}


