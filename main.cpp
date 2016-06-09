// курсач.cpp: определяет точку входа для консольного приложения.
//
#define _CRT_SECURE_NO_WARNINGS 
#include "stdafx.h"
#include <windows.h>
#include <winuser.h>
#include <Windows.h>
#include "symbol.h"
#include "My_Binary_File.h"
#include <stack>
#include "Derived_exception.h"
#include <iostream>
#include "Keyboard.h"
#include "conio.h"



enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};


void my_terminate()
{
	cout << "Обнаружено необработанное исключение!(terminate)" << endl;
	exit(1);
}
void my_unexpected()
{
	throw (1, "Необработанное исключение(unexpected)");
}

void fun(BinaryFileClass & claf_bin, Last_action& stek){
	int ch;
	int num;
	Data_list List2;
	BinarySearchTree<Claf> data;
	char c;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (1){
		system("cls");
		cout << endl << endl;
		cout << " Выберите действие " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. Просмотр " << endl;
		cout << " 2. Удаление данных  " << endl;
		cout << " 3. Отмена последнего действия " << endl;
		cout << " 4. Количество нажатий(поиск по аски коду) " << endl;
		cout << " 5. Выход обратно " << endl;		
		ch = enter_INT(1,5);
		switch (ch)
		{
		case 1:
			system("cls");
			SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Green));
			cout << endl;
			cout << "--------------------------" << endl;
			claf_bin.read_all(List2);						
			List2.show_list();
			cout << endl;
			SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));
			system("pause");
			break;
		case 2:
			system("cls");
			cout << endl;
			cout << "--------------------------" << endl;
			cout << "Введите количество клавиш,которые будут удалены с конца : ";
			num=enter_INT();
			claf_bin.del_elements(stek, num);
			system("pause");
			break;
		case 3:
			claf_bin.cancel(stek);
			system("pause");
			break;
		case 4:
			system("cls");
			cout << endl;
			cout << "--------------------------" << endl;
			cout << "Введите клавишу : ";
			num = _getch();
			if (num < 0) num = 256 + num;			
			claf_bin.read_all(List2);
			data=link(List2);
			data.search_it(num);
			//data.print_inorder();
			system("pause");
			break;
		case 5: return;
		default:break;
		}
		system("cls");
	}
	
}



int main(){
	set_terminate(my_terminate);
	set_unexpected(my_unexpected);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Data_list List2, List3, cur, cur1;
	Last_action STACK;
	BinaryFileClass claf_bin("Data_list.dat");	
	setlocale(LC_ALL, "Russian");
	int ch, t = 0;
	List2.clear_file();
	SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));
	system("mode con lines=30 cols=100");
	while (1){
		system("cls");
		cout << endl << endl;
		cout << " Выберите действие " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. Начать новый сеанс(все данные с предыдущих сеансов будут уничтожены) " << endl;
		cout << " 2. Продолжить  " << endl;
		cout << " 3. Операции с данными " << endl;
		cout << " 4. Выход из программы " << endl;	
		ch = enter_INT(1,4);
		switch (ch)
		{
		case 1:
			system("cls");
			SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Blue));
			cout << endl;
			cout << "Считывание клавиш прекратится по нажатию клавиши ESCAPE";
			if (t == 0){
				HACKER(NULL);
			}
			List2.read_file();
			claf_bin.add_new_elements(List2, 1, STACK);			
			List2.clear_file();
			SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));
			system("pause");
			break;
		case 2: cout << endl;
			if (t==0)
			system("cls");
			SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Blue));
			HACKER(NULL);
			List2.read_file();
			claf_bin.add_new_elements(List2, 0, STACK);
			SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));
			List2.clear_file();
			system("pause");
			break;
		case 3:
			fun(claf_bin, STACK);
			break;

		case 4: return 0;
		default:break;
		}
		system("cls");
	}

	return 0;
}

