#ifndef NODE_
#define NODE_

template<class T>
class Node {
public:
	T data;
	Node<T>* next;
	Node() {
		next = nullptr; 
	}
	Node(T item) {
		data = item;
		next = nullptr;
	}
	
};


#endif