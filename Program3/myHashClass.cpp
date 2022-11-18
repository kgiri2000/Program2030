//myHashClass.cpp
//Kamal Giri

#include "myHashClass.h"

template<class T>
myHashClass<T>::myHashClass() {
	for (int i = 0; i < HASHSIZE; i++) {
		hashA[i] = nullptr;
	}
	size = 0;
}

template<class T>
int myHashClass<T>::hasher(T item) {
	long long int val = 0;
	for (int i = 0; i < item.length(); i++) {
		val = (val * HASHSIZE) + int(item[i]);
	}
	return val % HASHSIZE;

}

template<class T>
void myHashClass<T> :: insert(T item){
	int key = hasher(item);
	addNode(item, hashA[key]);
}

template<class T>
bool myHashClass<T> ::find(T data, int& compares) {
	int key = hasher(data);
	if (find(data, hashA[key], compares) != nullptr) {
		return true;
	}
	else {
		return false;
	}

}

template<class T>
void myHashClass<T> ::addNode(T item, myNode<T>*& t) {
	if (t = nullptr) {
		t = new myNode<T>(item);
		size++;
	}
	int val = item.compare(t->data);
	if (val < 0) {
		addNode(item, t->left);
	}
	else if(val>0) {
		addNode(item, t->right);

	}
}

template<class T>
myNode<T>* myHashClass<T> ::find(T item, myNode<T>* t, int& compares) {
	if (t == nullptr) {
		return nullptr;
	}
	int temp = item.compare(t->data);
	if (temp < 0) {
		compares++;
		return find(item, t->left, compares);
	}
	else if (temp > 0) {
		compares++;
		return find(item, t->right, compares);
	}
	else {
		compares++;
		return t;

	}

}