#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

template <class T>
//LinkedList Node
class Node {
public:
	T data;//�����͸� ������ ����
	Node<T>* link;//��屸��ü �̿�; ��������� �ּҸ� ������ ������
	Node<T>(T element) {
		data = element;
		link = 0;
	}
};
template <class T>
//LinkedList Class
class LinkedList {
protected:
	Node<T>* first;//ù��° ����� �ּҸ� ������ ������
	int current_size; //����� ����
public:
	//������, �ʱ�ȭ 
	LinkedList() {
		first = 0;
		current_size = 0;
	};

	//��� ������ ����
	T GetSize() {
		return current_size;
	};

	//�� �տ� ���Ҹ� ����, LinkedList�� Stack �Ѵ� ����
	void Insert(T element);

	//�� ���� ���Ҹ� ����, ���� ���߿� ���� ���� ����  - LinkedList
	virtual bool Delete(T& element);

	//����Ʈ ���
	void Print();
};

template <class T>
//�� ��带 �� �տ� ���̰� ���� ����
void LinkedList<T>::Insert(T element) {
	//��� ����
	Node<T>* newnode = new Node<T>(element);

	//�� ��尡 ù��° ��带 ����Ŵ
	//newnode�� �������̱� ������ -> �� ����� �Լ�, ������ �ҷ��� (*newnode).link�� ���� ����
	newnode->link = first;
	first = newnode;
	current_size++;
}
template <class T>
//������ ����� ���� �����ϸ鼭 �޸𸮿��� �Ҵ� ����
bool LinkedList<T>::Delete(T& element) {

	if (first == 0)
		return false;

	Node<T>* current = first;
	Node<T>* previous = 0;

	//������ ������ ã�ư��� �ݺ���
	while (1) {
		if (current->link == 0) {  //������ ��带 ã�°�
			if (previous)
				previous->link = current->link;
			else
				first = first->link;
			break;
		}
		previous = current;
		current = current->link;
	}
	element = current->data;
	delete current;
	current_size--;

	return true;
}
template <class T>
//����Ʈ�� ����ϴ� Print �Լ�
void LinkedList<T>::Print() {
	Node<T>* i;
	int index = 1;

	if (current_size != 0) {
		for (i = first; i != NULL; i = i->link) {
			if (index == current_size) {
				cout << "[" << index << "|";
				cout << i->data << "]"; //���������� ȭ��ǥ ������
			}

			else {
				cout << "[" << index << "|";
				cout << i->data << "]->";
				index++;
			}
		}
		cout << endl;
	}

}


#endif
