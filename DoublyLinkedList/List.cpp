#include "List.h"

// Node Class
Node::Node(){}

Node::Node(TYPE data, Node* nextNode, Node* previousNode)
	: _data(data), _nextNode(nextNode), _previousNode(previousNode) {}

// List Class

List::List()
{
	_head = nullptr;
	_tail = _head;
	_qty = 0;
}

List::~List()
{
	this->clear();
}

bool List::isEmpty() const
{
	if (_head == nullptr)
	{
		return true;
	}
	return false;
}

bool List::isFull() const
{
	Node* node = new Node();
	if (node == nullptr)
	{
		return true;
	}
	node = nullptr;
	return false;
}

std::string List::toString() const
{
	if (isEmpty())
	{
		return "null";
	}
	std::stringstream ss;
	Node* ptr = _head;
	while (ptr->getNextNode() != _head)
	{
		ss << ptr->getData();
		ss << ";";
		ptr = ptr->getNextNode();
	}
	// For the last node 
	ss << ptr->getData();
	return ss.str();
}

Node* List::find(TYPE data) const
{
	if (isEmpty())
	{
		return nullptr;
	}
	Node* ptr = _head;
	if (ptr->getData() == data)
	{
		return ptr;
	}
	while (ptr->getNextNode() != _head && ptr->getData() != data)
	{
		ptr = ptr->getNextNode();
	}

	//if (!(ptr != _head && ptr->getData() == data))
	//{
	//	return nullptr;
	//} 
	// De Morgan
	if (ptr == _head || ptr->getData() != data)
	{
		return nullptr;
	}
	return ptr;
}

Node* List::remove(TYPE data) const
{
	return nullptr;
}

bool List::insert()
{
	return false;
}

bool List::clear()
{
	return false;
}
