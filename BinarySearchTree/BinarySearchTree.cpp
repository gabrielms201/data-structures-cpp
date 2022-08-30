#include "BinarySearchTree.h"

void Node::Insert(TYPE value)
{
	if (value > _data)
	{
		if (_right == nullptr)
		{
			_right = new Node(value);
		}
		else
		{
			_right->Insert(value);
		}
	}
	else
	{
		if (_left == nullptr)
		{
			_left = new Node(value);
		}
		else
		{
			_left->Insert(value);
		}
	}

}
Node* Node::Delete(Node* node, TYPE data)
{
	if (node == nullptr)
	{
		return node;
	}
	if (data < node->_data)
	{
		node->_left = Delete(node->_left, data);
		return node;
	}
	else if (data > node->_data)
	{
		node->_right = Delete(node->_right, data);
		return node;
	}

	// Now we found which node to delete

	// If the left is null, we return the right child
	if (node->_left == nullptr)
	{
		Node* temp = node->_right;
		delete node;
		node = nullptr;
		return temp;
	}
	// If the right is null, we return the left child
	else if (node->_right == nullptr)
	{
		Node* temp = node->_left;
		delete node;
		node = nullptr;
		return temp;
	}
	// If both children are not null
	else
	{
		Node* tempPtr = node;
		
		Node* sucessor = node->_right;

		// We find the sucessor with no left child
		while (sucessor->_left != nullptr)
		{
			tempPtr = sucessor;
			sucessor = tempPtr->_left;
		}

		// If the tempPtr is different from the node , then the left root will be the sucessor's right node
		if (tempPtr != node)
		{
			tempPtr->_left = sucessor->_right;
		}
		// Otherwise, the right tempPtr will be the sucessor's right node
		else
		{
			tempPtr->_right = sucessor->_right;
		}
		// Now we pass the crown from the sucessor to the data.
		node->_data = sucessor->_data;
		delete sucessor;
		sucessor = nullptr;
		return node;
	}
}

Node::Node(TYPE value)
	: _data(value), _right(nullptr), _left(nullptr)
{
}
Node::~Node()
{

}

Node* BST::Search(TYPE value) const
{
	Node* node = nullptr;
	node = _root;
	while (node != nullptr && node->_data != value)
	{
		if (value > node->_data)
		{
			node = node->_right;
		}
		else
		{
			node = node->_left;
		}
	}
	return node;
}

BST::BST()
	: _root(nullptr)
{
}

BST::~BST()
{
}

void BST::Insert(TYPE value)
{
	if (_root == nullptr)
	{
		_root = new Node(value);
		return;
	}
	_root->Insert(value);
}

Node* BST::Remove(TYPE data)
{
	/*if (_root == nullptr)
	{
		return _root;
	}*/
	Node* node = _root->Delete(_root, data);
	return node;
}
