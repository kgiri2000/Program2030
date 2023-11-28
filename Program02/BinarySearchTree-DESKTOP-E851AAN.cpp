#include<iostream>
#include<string>
#include "BinarySearchTree.h"
using namespace std;

//constructor 
template<class T>
BinarySearchTree<T> ::BinarySearchTree() {
	root = nullptr;
	size = 0;
}
//destructor

template<class T>
BinarySearchTree<T>:: ~BinarySearchTree() {
	clear(root);

}

//to delete all the contents of the Binary Serch tree

template<class T>
void BinarySearchTree<T> ::clear(BinaryNode<T>* t) {
	if (t == nullptr) {
		return;
	}
	else {
		if ((t->left == nullptr) && (t->right == nullptr)) {
			delete t;
			t= nullptr;
		}
		else {
			clear(t->left);
			clear(t->right);
		}
	}

}

//insert
template<class T>
void BinarySearchTree<T>::insert(T item) {

	insert(item, root);
	
	
}

template<class T>
void BinarySearchTree<T>::insert(T item, BinaryNode<T>*& t) {
	//there is no any root so we create a new root 
	if (t == nullptr) {
		t = new BinaryNode<T>(item); // we created a new binary node class with data = item and left = right = nullptr
		size++;
	}
	else if (item < t->data) {
		insert(item, t->left);
	}
	else if (item > t->data) {
		insert(item, t->right);
	}
	else {
		//do nothing
	}
	
	
}

//Removing
template<class T>
void BinarySearchTree<T>::insert(T item) {
	remove(T item,root);


}
template<class T>
void BinarySearchTree<T> ::remove(T item, BinaryNode<T>*& t);

//Find functions
template<class T>
BinaryNode<T>* BinarySearchTree<T> ::find(T item, BinaryNode<T>* t) {
	if (t == nullptr) {
		return nullptr;
	}
	else if (item < t->data) {
		return find(item, t->left);
	}
	else if (item > t->data) {
		return find(item, t->right);
	}
	else {
		return t;
	}

}

template<class T>
void BinarySearchTree<T> ::prePrint() {
	prePrint(root);
}
//printing everything
template<class T>
void BinarySearchTree<T> ::prePrint(BinaryNode<T>* t) {
	if (t == nullptr) {
		return;
	}
	prePrint(t->left);
	prePrint(t->right);
	cout << t -> data << endl;

}


