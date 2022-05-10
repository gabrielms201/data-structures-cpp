#ifndef LIST_H
#define LIST_H

typedef int TYPE;
#include <iostream>
#include <sstream>
#include <ostream>
#include <string>

// Node class
class Node
{
public:
	Node();
	Node(TYPE data, Node* nextNode, Node* previousNode);
	~Node() {};

	TYPE getData() const { return _data; };
	Node* getNextNode() const { return _nextNode; };
	Node* getPreviousNode() const { return _previousNode; }

	void setNextNode(Node* node) { _nextNode = node; }
	void setPreviousNode(Node* node) { _previousNode = node; }
private:
	TYPE _data;
	Node* _nextNode;
	Node* _previousNode;
};

// List Class
class List
{
public:
	List();
	~List();

	Node* getHead() const { return _head; }
	Node* getTail() const { return _tail; }
	unsigned int getQty() const { return _qty; }
	
	void setHead(Node* head) { _head = head; }
	void setTail(Node* tail) { _tail = tail; }
	void setQty(unsigned int qty) { _qty = qty; }

	bool isEmpty() const;
	bool isFull() const;
	std::string toString() const;
	Node* find(TYPE data) const;			// O(n)

	bool remove(TYPE data);				// O(n)
	void insert(TYPE data);					// O(1)
	void clear();

private:
	Node* _head;
	Node* _tail;
	unsigned int _qty;

};
inline std::ostream& operator << (std::ostream& str, const List& list)
{
	return str << list.toString();
}
#endif // #ifndef LIST_H