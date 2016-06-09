#include"stdafx.h"
#include"Claf.h"

using namespace std;

//установить клавишу
void Claf::set_Claf(char *str, int M)
{
	this->line = str;//передаем название
	this->ascii_num = M;// аски код
}
//конструктор по умолчанию
Claf::Claf() :symbol(){}
//конструктор копирования
Claf::Claf(const Claf &x)
{
	this->line = x.line;
	this->ascii_num = x.ascii_num;
}

void Claf::write_b(fstream &file)
{
	char buf[20];
	strcpy(buf, line.c_str());//записываем в статический массив
	file.write(buf, sizeof(buf));//записываем в файл
	file.write(reinterpret_cast<char*>(&ascii_num), sizeof(int));
}

void Claf::read_b(fstream &file)
{
	char buf[20];
	file.read(buf, sizeof(buf));//читаем 20 байт
	line = buf;//записываем название клавиши
	int asc;
	file.read(reinterpret_cast<char*>(&asc), sizeof(int));
	ascii_num = asc;//и аски кода 
}

Claf::~Claf(){}

string Claf::get_Claf()
{
	return this->line;
}

//перегрузка вывода
ostream& operator<<(ostream& file, Claf obj)
{
	file << obj.line;
	file << "    ";
	file << obj.ascii_num;
	return file;
}

//выводим на печать имя клавиши
void Claf::show_Claf(){
	cout << this->line;	
}

//перегрузка операторов
int Claf::operator==(int x){
	if (this->ascii_num == x) return 1;
	return 0;
}

int Claf::operator!=(int x ){
	if (this->ascii_num != x) return 1;
	return 0;
}

int Claf::operator>(int x){
	if (this->ascii_num > x) return 1;
	return 0;
}

int Claf::operator<(int x){
	if (this->ascii_num < x) return 1;
	return 0;
}


int Claf::operator==(Claf &x){
	if (this->ascii_num == x.ascii_num) return 1;
	return 0;
}

int Claf::operator!=(Claf &x){
	if (this->ascii_num != x.ascii_num) return 1;
	return 0;
}

int Claf::operator>(Claf &x){
	if (this->ascii_num > x.ascii_num) return 1;
	return 0;
}

int Claf::operator<(Claf &x){
	if (this->ascii_num < x.ascii_num) return 1;
	return 0;
}