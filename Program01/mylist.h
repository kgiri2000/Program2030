#ifndef MYLIST_
#define MYLIST_
#include "Node.h"

template<class T>
class myList {
private:
	Node<T>* head;
	int size;
public:
	long long int compares;
	long long int ucompares;
	myList();
	~myList();
	void remove();
	T front();
	void insert(T item);
	void print();
	bool isEmpty() {
		return size ==0;
	}
	int getSize() {
		return size;
	}
	bool findItem(T item);
	long long int getCompares() {
		return compares;
	}
	long long int getuCompares() {
		return ucompares;
	}

};




#endif