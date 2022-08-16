#include <iostream>
#include <vector>
#include "BinarySearchTree.h"
const char* boolToString(const bool value)
{
	return value ? "true" : "false";
}

void populateVector(std::vector<int>& vec, size_t size)
{

	for (int i = 0; i < size; i++)
	{
		int value = rand();
		vec.push_back(value);
	}
}

int main(int argc, char* argv[])
{
	srand(time(NULL));
	BST tree = BST();

	std::vector<int> values;
	populateVector(values, 1000000);
	for (int i = 0; i < values.size(); i++)
	{
		tree.Insert(values[i]);
	}
	bool foundEverything = true;
	for (int i = 0; i < values.size(); i++)
	{
		Node* node = tree.Search(values[i]);
		if (node == nullptr)
		{
			foundEverything = false;
		}
	}





	std::cout << boolToString(foundEverything);
}