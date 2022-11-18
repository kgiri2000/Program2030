// myHashClass.h
// Kamal Giri


#ifndef MYHASHCLASS_h
#define MYHASHCLASS_h



template<class T>
class myNode
{
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

template<class T>
class myHashClass
{
private:
	#define HASHSIZE 393241
	myNode<T>* hashA[HASHSIZE];
	void addNode(T item, myNode<T>*& t);
	myNode<T>* searchNode(T item, myNode<T>* t, int& compares);

public:
	int size;
	myHashClass();
	void insert(T item);
	bool find(T item, int& compares);
	int hasher(T item);
	int getSize() { return size; }
};


#endif