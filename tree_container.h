#include <iostream>
#include <stack>


using namespace std;


template <class T>//��������� ���� 
struct tree_node
{
	tree_node *left;
	tree_node *right;
	T obj;
	int repeats;
};

template <class T>
class Iterator;

template <class T>
class BinarySearchTree
{

	tree_node<T> *root;//������ ������

public:	
	template <class T>
	//������������� ����� ��������
	friend class Iterator;

	BinarySearchTree()
	{
		root = NULL;
	}
	int isEmpty() const{ return root == NULL; }
	void insert(T);
	void search(int);	
	void print_inorder();
	void inorder(tree_node<T>*);
	tree_node<T>* begin();
	int search_it(int);
	int show_repeats();
	void look_stack_tree1();
	void look_stack1(Iterator<T> &);

	
};


template <class T>
class Iterator{
	tree_node<T> *pointer;//��������� �� ����
	stack<tree_node<T>*> s;//���� ����������
public:
	Iterator(tree_node<T> *ptr) : pointer(ptr) {}
	Iterator(const Iterator &ptr) : pointer(ptr.pointer), s(ptr.s){ }
	~Iterator(){}
	void Push(){
		this->s.push(this->pointer);
	}
	//�������� �� ������ ��� ���
	int IsEmpty(){
		if (this->s.empty()) return 0;
		return 1;
	}
	Iterator& Pop(){
		this->pointer = s.top();
		s.pop();
		return *this;
	}
	Iterator()
	{
		pointer = NULL;
	}
	//���� � ����� ���������
	Iterator& operator ++ ()
	{
		if (!pointer->left || !pointer)
			this->pointer = NULL;
		else
		{
			//	Push();
			pointer = pointer->left;
		}
		return *this;
	}
	//���� � ������ ���������
	Iterator& operator ++ (int)
	{
		if (!pointer)
			this->pointer = NULL;//���� ���������� ��������� ������� ���������
		if (!pointer->right)
			this->pointer = NULL;
		else
		{
			//	Push();
			pointer = pointer->right;
		}
		return *this;
	}

	Iterator& operator -- (int)
	{
		if (!pointer || s.empty())
			throw(1, "Pointer �� ������������������");
		else{
				this->pointer=s.top();//�������� ���������� ���������
				s.pop(); //������� �������� �� ����������
			return *this;
		}
	}
	int operator ==(const Iterator& ob)
	{
		if (pointer == ob.pointer) return 1;
		return 0;
	}
	int operator !=(const Iterator& ob)
	{
		return !(pointer == ob.pointer);
	}
	T& operator*()
	{ 
		return pointer->obj;
	}
	int show_repeats()
	{
		return pointer->repeats;
	}
	Iterator &operator = (Iterator &ob)
	{
		if (ob.pointer != pointer)
			pointer = ob.pointer;
		return *this;
	}
};
