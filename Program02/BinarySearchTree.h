#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

#include "BinaryNode.h"
template<class T>
class BinarySearchTree {
private:
	BinaryNode<T>* root;
	int size;
	void insert(T item, BinaryNode <T>*& t);
	void clear(BinaryNode <T>* t);
	void prePrint(BinaryNode<T>* t);
	BinaryNode<T>* find(T item, BinaryNode<T>* t);
	void remove(T item, BinaryNode<T>*& t);
	//BinaryNode<T>* findMin(BinaryNode<T>* t);
	//BinaryNode<T>* findMax(BinaryNode<T>* t);

public:
	long long int compares;
	long long int ucompares;

	void insert(T item);

	//constructor
	BinarySearchTree();
	//destructor
	~BinarySearchTree();
	//method to get the size of dictonary
	int getSize() {
		return size;
	}
	//getting minimum
	//BinaryNode* findMin();
	BinaryNode<T>* findMin(BinaryNode<T>* t) {
		if (t == nullptr)
		{
			return nullptr;
		}
		else if (t->left == nullptr) {
			return t;
		}
		return findMin(t->left);
	}

	//Getting maximun
	//BinaryNode* findMax();
	BinaryNode<T>* findMax(BinaryNode<T>* t) {
		if (t == nullptr)
		{
			return nullptr;
		}
		else if (t->right == nullptr) {
			return t;
		}
		return findMin(t->right);
	}

	//Finding the items
	BinaryNode<T>* find(T item) {
		return find(item, root);
	}

	//For removal operation
	void remove(T item) {
		remove(item, root);
	}
	bool isEmpty() {
		return size == 0;
	}
	void prePrint();


	long long int getCompares() {
		return compares;
	}
	long long int getuCompares() {
		return ucompares;
	}
};





#endif
