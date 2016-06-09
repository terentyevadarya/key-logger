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
	//устанавливаем на красный цвет
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 4));
	output << "код ошибки(" << ex.error_code << ") : " << ex.error_name << endl;
	//обратно черный цвет шрифта
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
			if (!cin || cin.peek() != '\n')//если введено не число
			{

				throw Derived_Exception
					(6, "¬ведите число,а не символы");
			}//если отрицательное
			if (buf<0) throw Derived_Exception
				(7, "„исло вне диапазона данных,повторите");;
			if (buf<beg || buf>end)//или выходит из заданного диапазона
				throw Derived_Exception
				(7, "„исло вне диапазона данных,повторите");
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
				throw Derived_Exception(7, "„исло вне диапазона данных,повторите");
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
				throw Derived_Exception(7, "„исло вне диапазона данных,повторите");
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
				throw Derived_Exception(6, "¬ведите число,а не символы");
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