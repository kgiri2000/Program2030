//myHashClass.h
//Kamal Giri

#ifndef MYHASHCLASS_H
#define MYHASHCLASS_H

#define HASHSIZE 399991

//Node Class
template<class T>
class myNode {
public:
	T data;
	myNode<T>* left;
	myNode<T>* right;
	myNode(T d) {
		data = d;
		left = nullptr;
		right = nullptr;
	}
};

//Hash Class
template<class T>
class myHashClass {
private:
	int size;
	myNode<T>* hashA[HASHSIZE];
	void addNode(T item, myNode<T>*& t);
	myNode<T>* find(T item, myNode<T>* t, int& copmares);
public:
	myHashClass();
	void insert(T item);
	bool find(T item, int& compares);
	int hasher(T item);
	int getSize() {
		return size;
	}
};

#endif