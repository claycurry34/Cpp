#include "RedBlackBST.h"

int main()
{
	RedBlackBST<char> bst;

	char inserts[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char deletes[] = "ZBXDVFTSHQKONMLPJIRGUEWCYA";

	try
	{
		for (int i = 0; i < 26; i++)
		{
			bst.insert(inserts[i]);
		}
		bst.printTree(std::cout, 1);

	}
	catch (std::exception e)
	{
		std::cout << "Exception" << std::endl;
	}
}