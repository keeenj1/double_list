#include <iostream>
#include <vector>
#include <list>

struct Node {
	int data;
	Node* next;
	Node* prev;
};

class double_list {
public:
	double_list();
	double_list(int Data);
	bool add_element(int data);
	void delete_element(int data);
	bool find_element(int data);
	bool insert(int data, int position);
	void print();
	void obr_print();
	void sort();
private:
	Node* first;
	Node* last;
};

double_list::double_list() {
	first = nullptr;
	last = nullptr;
}
double_list::double_list(int data) {
	Node* nd = new Node{ data, nullptr };
	first = nd;
	last = nd;
	//last->next = nullptr;
}
bool double_list::add_element(int data) {
	Node* nd = new Node{ data, nullptr, nullptr };
	if (last == nullptr) {
		first = nd;
		last = nd;
	}
	else {
		nd->prev = last;
		last->next = nd;
		last = nd;
	}
	return true;
}
void double_list::delete_element(int value) {
	Node* current = first;
	while (current != nullptr) {
		if (current->data == value) {
			if (current->prev != nullptr) {
				current->prev->next = current->next;
			}
			if (current->next != nullptr) {
				current->next->prev = current->prev;
			}
			if (current == first) {
				first = current->next;
			}
			delete current;
			break;
		}
		current = current->next;
	}
}
bool double_list::find_element(int value) {
	int i = 0;
	Node* PP = first;
	while (PP) {
		if (PP->data == value)
		{
			i = i + 1;
		}
		PP = PP->next;
	}
	if (i == 0) {
		return false;
	}
	return true;
}
bool double_list::insert(int data, int pos) {
	Node* nd1 = first;
	Node* nd2 = new Node{ data,nullptr,nullptr };
	if (pos == 0) {
		nd2->next = first;
		first->prev = nd2;
		first = nd2;
		return true;
	}
	int i = 1;
	while (nd1 != nullptr) {
		if (i == pos) {
			nd2->prev = nd1;
			nd2->next = nd1->next;
			if (nd1->next != nullptr) {
				nd1->next->prev = nd2;
			}
			nd1->next = nd2;
			break;
		}
		nd1 = nd1->next;
		++i;
	}
}
void double_list::print() {
	Node* PP = first;
	while (PP) {
		std::cout << PP->data << " ";
		PP = PP->next;
	}
	std::cout << std::endl;
}
void double_list::obr_print() {
	Node* PP = last;
	while (PP) {
		std::cout << PP->data << " ";
		PP = PP->prev;
	}
	std::cout << std::endl;
}
void double_list::sort() {
	Node* nd = new Node;
	Node* left = first;
	Node* right = first->next;
	while (left->next) {
		while (right) {
			if ((left->data) > (right->data)) {
				nd->data = left->data;
				left->data = right->data;
				right->data = nd->data;
			}
			right = right->next;
		}
		left = left->next;
		if (left != nullptr) {
			right = left->next;
		}
	}
	delete nd;
}

int main()
{
	// Создаём список (двусвязный)
	double_list lst;
	lst.add_element(5);
	lst.add_element(10);
	lst.add_element(15);
	lst.add_element(20);
	lst.add_element(25);
	// Выводим список обычный и перевёрнутый
	std::cout << "List: ";
	lst.print();
	std::cout << "Reversed list: ";
	lst.obr_print();
	// Удаляем элемент
	lst.delete_element(15);
	std::cout << "List without 15: ";
	lst.print();
	// Вставляем элемент 
	lst.insert(333, 3);
	std::cout << "List with inserted number: ";
	lst.print();
	// Сортируем 
	lst.sort();
	std::cout << "Sorted list: "; lst.print();

	return 0;
}