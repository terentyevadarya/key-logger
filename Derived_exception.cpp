#pragma once
#include "Derived_Exception.h"
#include <Windows.h>

Derived_Exception::Derived_Exception() :My_Exception()
{
	error_name = NULL;
}

Derived_Exception::~Derived_Exception()
{
	delete[] error_name;
}

Derived_Exception::Derived_Exception(const Derived_Exception &x)
{
	error_name = new char[strlen(x.error_name) + 1];
	strcpy(error_name, x.error_name);
	error_code = x.error_code;
}

Derived_Exception::Derived_Exception(int i, char *s)
{
	error_name = new char[strlen(s) + 1];
	strcpy(error_name, s);
	error_code = i;
}

ostream &operator <<(ostream &output, Derived_Exception &ex)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//������������� �� ������� ����
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 4));
	output << "��� ������(" << ex.error_code << ") : " << ex.error_name << endl;
	//������� ������ ���� ������
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
	return output;
}

int enter_INT(int beg, int end) throw(Derived_Exception)
{
	bool fl = false;
	int buf = 0;
	do
	{
		try
		{
			cin >> buf;
			fl = true;
			if (!cin || cin.peek() != '\n')//���� ������� �� �����
			{

				throw Derived_Exception
					(6, "������� �����,� �� �������");
			}//���� �������������
			if (buf<0) throw Derived_Exception
				(7, "����� ��� ��������� ������,���������");;
			if (buf<beg || buf>end)//��� ������� �� ��������� ���������
				throw Derived_Exception
				(7, "����� ��� ��������� ������,���������");
		}
		catch (Derived_Exception &ex)
		{
			cout << ex;
			fl = false;
			cin.clear();
			cin.sync();
		}		
	} while (fl == false);
	return buf;
}


int check_INT(int beg, int end,int check) throw(Derived_Exception)
{
	bool fl = false;
	int buf = check;
	do
	{
		try
		{				
			if (buf<beg || buf>end)
				throw Derived_Exception(7, "����� ��� ��������� ������,���������");
		}
		catch (Derived_Exception &ex)
		{
			cout << ex;
			fl = false;
			cin.clear();
			cin.sync();
		}		
	} while (fl == false);
	return buf;
}

int check_NULL(int check) throw(Derived_Exception)
{
	bool fl = false;
	int buf = check;
	do
	{
		try
		{
			if (buf==0)
				throw Derived_Exception(7, "����� ��� ��������� ������,���������");
		}
		catch (Derived_Exception &ex)
		{
			cout << ex;
			fl = false;
			cin.clear();
			cin.sync();
		}
	} while (fl == false);
	return buf;
}

int enter_INT() throw(Derived_Exception)
{
	bool fl = false;
	int buf = 0;
	do
	{
		try
		{
			cin >> buf;
			fl = true;
			if (!cin || cin.peek() != '\n')
			{
				throw Derived_Exception(6, "������� �����,� �� �������");
			}			
		}
		catch (Derived_Exception &ex)
		{
			cout << ex;
			fl = false;
			cin.clear();
			cin.sync();
		}		
	} while (fl == false);
	return buf;
}