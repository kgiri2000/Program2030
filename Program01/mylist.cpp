#include<iostream>
#include<string>
#include "mylist.h"
using namespace std;




template<class T>
myList<T> ::myList() {

	head = nullptr;
	size = 0;

	long long int compares = 0;
	long long int ucompares = 0;
	
}
template<class T>
myList<T> :: ~myList() {
	while (!isEmpty()) {
		remove();
	}
}
template<class T>
void myList<T>::remove() {
	Node<T>* tmp;
	if (head != nullptr) {
		while (head != nullptr)
		{
			tmp = head;
			head = head->next;
			delete tmp;
		}
		size--;
	}
}
template<class T>
T myList<T> :: front() {
	T tmp = T(0);
	if (head != nullptr) {
		return tmp;
	}
}
template<class T>
void myList<T>::insert(T item) {
	Node<T>* tmp = new Node <T>(item);
	tmp->next = head;
	tmp->data = item;
	head = tmp;
	size++;
}
template<class T>
void myList<T>::print() {
	for (Node<T>* tmp = head;
		tmp != nullptr;
		tmp = tmp->next) {
		cout << tmp->data;
		cout << endl;
		
	}

}
template<class T>
bool myList<T> ::findItem(T word)
{
	Node<T>* tmp = new Node <T>(word);
	tmp = head;
	
	int long long count = 0;
	while (tmp != nullptr) {
		count++;
		if (tmp -> data.compare(word) == 0)
		{
			compares = count + compares;
			return true;
		}
		tmp = tmp->next;
	}
	ucompares = count + ucompares;
	return false;
}










