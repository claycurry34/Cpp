#include "BinarySearchTree.h"


int main()
{
	BinarySearchTree<char> bst('Q');
	std::cout << bst << std::endl;
	bst.insert('J');
	std::cout << bst << std::endl;
	bst.insert('A');
	std::cout << bst << std::endl;
	bst.insert('S');
	std::cout << bst << std::endl;
	bst.insert('B');
	std::cout << bst << std::endl;
	bst.insert('E');
	std::cout << bst << std::endl;

}