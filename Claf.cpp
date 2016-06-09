#include"stdafx.h"
#include"Claf.h"

using namespace std;

//���������� �������
void Claf::set_Claf(char *str, int M)
{
	this->line = str;//�������� ��������
	this->ascii_num = M;// ���� ���
}
//����������� �� ���������
Claf::Claf() :symbol(){}
//����������� �����������
Claf::Claf(const Claf &x)
{
	this->line = x.line;
	this->ascii_num = x.ascii_num;
}

void Claf::write_b(fstream &file)
{
	char buf[20];
	strcpy(buf, line.c_str());//���������� � ����������� ������
	file.write(buf, sizeof(buf));//���������� � ����
	file.write(reinterpret_cast<char*>(&ascii_num), sizeof(int));
}

void Claf::read_b(fstream &file)
{
	char buf[20];
	file.read(buf, sizeof(buf));//������ 20 ����
	line = buf;//���������� �������� �������
	int asc;
	file.read(reinterpret_cast<char*>(&asc), sizeof(int));
	ascii_num = asc;//� ���� ���� 
}

Claf::~Claf(){}

string Claf::get_Claf()
{
	return this->line;
}

//���������� ������
ostream& operator<<(ostream& file, Claf obj)
{
	file << obj.line;
	file << "    ";
	file << obj.ascii_num;
	return file;
}

//������� �� ������ ��� �������
void Claf::show_Claf(){
	cout << this->line;	
}

//���������� ����������
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