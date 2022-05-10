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
	return (_head == nullptr);
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

	// If is not at the beginning, search for it:
	while (ptr->getNextNode() != nullptr && ptr->getData() != data)
	{
		ptr = ptr->getNextNode();
	}

	// If we didn't found it:
	if (ptr->getData() != data)
	{
		return nullptr;
	} 
	return ptr;
}

bool List::remove(TYPE data)
{
	Node* node = find(data);

	if (_tail == _head && _head == node)
	{
		_qty--;
		delete node;
		_tail = nullptr;
		_head = nullptr;
		return node;
	}
	if (_tail == node)
	{
		Node* prev = node->getPreviousNode();
		prev->setNextNode(nullptr);
		_tail = prev;
		_qty--;
		delete node;
		return node;
	}

	if (_head == node)
	{
		Node* next = node->getNextNode();
		next->setPreviousNode(nullptr);
		_head = next;
		_qty--;
		delete node;
		return node;
	}

	if (node) // = node != nullptr
	{
		Node* prev = node->getPreviousNode();
		Node* next = node->getNextNode();
		prev->setNextNode(node->getNextNode());
		next->setPreviousNode(prev);
		_qty--;
		delete node;
	}
	return node;
}

void List::insert(TYPE data)
{
	Node* node = new Node(data, nullptr, nullptr);
	// If the list is empty, then we add the node in the head and make it point to itself
	if (isEmpty())
	{
		_head = node;
		_tail = node;
		node->setPreviousNode(nullptr);
		node->setNextNode(nullptr);
		_qty++;
		return;
	}
	// If the list isn't empty, then we append the given data to the tail
	Node* ptr = _tail;
	ptr->setNextNode(node);
	node->setNextNode(nullptr);
	node->setPreviousNode(_tail);
	_tail = node;
	_qty++;
}

void List::clear()
{
	Node* ptr = _head;
	Node* prev = _head;


	while (ptr)
	{
		prev = ptr;
		ptr = ptr->getNextNode();
		prev->setNextNode(nullptr);
		delete prev;
		prev = nullptr;
		_qty--;
	}
	_head = nullptr;
	_tail = nullptr;


	//Node* ptr = _head;

	//while (ptr)
	//{
	//	//ptr->getPreviousNode() 
	//	ptr = ptr->getNextNode();
	//	ptr->getPreviousNode()->setNextNode(nullptr);
	//	delete ptr->getPreviousNode();
	//	ptr->setPreviousNode(nullptr);
	// 	_qty--;
	//}

}
