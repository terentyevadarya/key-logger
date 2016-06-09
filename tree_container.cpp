#include "stdafx.h"
#include "tree_container.h"
#include <iomanip>

template <class T>
void BinarySearchTree<T>::insert(T d)
{
	tree_node<T> *t = new tree_node<T>;
	tree_node<T> *parent;
	t->obj = d;
	t->left = NULL;
	t->right = NULL;
	t->repeats = 1;
	parent = NULL;
	if (isEmpty()) root = t;
	else
	{
		tree_node<T> *cur;
		cur = root;
		while (cur)
		{
			if (t->obj == cur->obj)
			{
				(cur->repeats)++;
				break;
			}
			if ((t->obj) < (cur->obj))
				if (!cur->left){
				cur->left = t;
				break;
				}
				else cur = cur->left;

				if ((t->obj) > (cur->obj))
					if (!cur->right){
					cur->right = t;
					break;
					}
					else cur = cur->right;
		}
	}
	//cout << "Элемент успешно добавлен!" << endl;
}

template<class T>
void BinarySearchTree<T>::print_inorder()
{
	inorder(root);
}

template<class T>
void BinarySearchTree<T>::inorder(tree_node<T> *p)
{
	if (p != NULL)
	{
		if (p->left) inorder(p->left);
		cout << p->obj << "(" << p->repeats << ") ";
		if (p->right) inorder(p->right);
	}
	else return;
}


template <class T>
void BinarySearchTree<T>::search(int d)
{

	int found = 0;
	if (!root)
	{
		cout << " Файл пуст! " << endl;
		return ;
	}
	tree_node<T>* curr;
	tree_node<T>* parent;
	curr = root;
	parent = (tree_node<T>*)NULL;
	while (curr != NULL)
	{
		if (curr->obj == d)
		{
			found = 1;
			break;
		}
		else
		{
			parent = curr;
			if (curr->obj<d) curr = curr->right;
			else curr = curr->left;
		}
	}
	if (!found)
	{
		cout << " Информация не найдена " << endl;
		system("pause");
	}
	else
	{
		cout << " Информация найдена! " << endl;
		cout << curr->obj;
		system("pause");
	}
	
}

template <class T>
tree_node<T>* BinarySearchTree<T>::begin()
{
	return root;
}



template <class T>
int BinarySearchTree<T>::search_it(int d){
	int ch;
	if (!(this->begin()))
	{
		cout << " Файл пуст! " << endl;
		return 0;
	}
	Iterator<T> curr = this->begin(), parent, com;
	int found = 0;

	while (curr != com)
	{
		if (*curr == d)
		{
			found = 1;
			break;
		}
		else
		{
			parent = curr;
			if (*curr<d) curr++;
			else ++curr;
		}
	}
	if (!found)
	{
		cout << " Информация не найдена " << endl;
		system("pause");
	}
	else
	{
		
		cout << " Информация найдена! " << endl;
		ch = curr.show_repeats();
		cout << endl;
		cout << "Клавиша" << "АSCII" << "Количество нажатий" << endl;
		cout << *curr << "(" << ch << ")" << "нажатий";
		
		system("pause");
	}

	return found;
}

template<class T>
void BinarySearchTree<T>::look_stack_tree1()
{
	Iterator<T> cur = this->begin();
	look_stack1(cur);
}



template<class T>
void BinarySearchTree<T>::look_stack1(Iterator<T> &cur)
{
	Iterator<T> cur_l = cur;
	Iterator<T> cur_r = cur;
	Iterator<T> Z;

	int pr = 1;
	cur.Push();
	if (cur == NULL) return;
	cur_r++;
	++cur_l;

	cout << *cur << endl;
	while (cur.IsEmpty() || cur_r != Z){
		do{
			if (pr && cur_l != Z) { cur = cur_l; cur_r = cur; cur_r++; ++cur_l; }
			else if (cur_r != Z)  { cur = cur_r; cur_l = cur; ++cur_l; cur_r++; }
			pr = 1;
			if (cur_l != Z && cur_r != Z)
				cur.Push();
			cout << *cur << endl;
		} while (cur_l != Z || cur_r != Z);
		if (cur.IsEmpty()){
			cur = cur.Pop();
			cur_l = cur_r = cur;
			++cur_l;
			cur_r++;
		}
		if (cur_r != Z) pr = 0;
	}

}
