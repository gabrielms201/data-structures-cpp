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

Node::Node(TYPE value)
	: _data(value), _right(nullptr), _left(nullptr)
{
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
