#pragma once


typedef int TYPE;


class Node
{
private:
	TYPE _data;
	Node* _right;
	Node* _left;
	friend class BST;
public:
	void Insert(TYPE value);
	Node(TYPE value);
	~Node();
	// Setters
	TYPE GetData() const { return _data; }
	Node* GetLeft() const { return _left; }
	Node* GetRight() const { return _right; }
	// Setters
	void SetData(TYPE data) { _data = data; }
	void SetLeft(Node* left) { _left = left; }
	void SetRight(Node* right) { _right = right; }

};
class BST
{
private:
	Node* _root;
public:

	Node* Search(TYPE value) const;

	// Setters
	Node* GetRoot() const { return _root; }
	// Setters
	void SetRoot(Node* root) { _root = root; }

	BST();
	~BST();
	void Insert(TYPE data);

};
