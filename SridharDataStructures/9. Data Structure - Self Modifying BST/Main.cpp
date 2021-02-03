#include"SelfModifyingBinarySearchTree.h"


int main()
{
	SelfModifyingBinarySearchTree<int> bst;

	char command;
	int val;
	int dir;
	
	std::cout << "Insert : I   Remove : R   Rotation : Z" << std::endl;
	
	while (std::cin >> command)
	{
		switch (command)
		{
		case 'I':
			std::cin >> val;
			bst.insert(val);
			bst.printTree(std::cout, 1);
			std::cout << std::endl;
			break;
		case 'R':
			std::cin >> val;
			bst.remove(val);
			bst.printTree(std::cout, 1);
			std::cout << std::endl;
			break;
		case 'Z':
			std::cout << "0. None   1. Zig   2. Zag   10. ZigZig   11. ZigZag   12. ZagZig   13. ZagZag" << std::endl;
			std::cin >> dir;
			if (dir > 12) bst.zagzag();
			else if (dir > 11) bst.zagzig();
			else if (dir > 10) bst.zigzag();
			else if (dir > 9) bst.zigzig();
			else if (dir > 1) bst.zag();
			else if (dir > 0) bst.zig();
			bst.printTree(std::cout, 1);
			std::cout << std::endl;
			break;
		default:
			return 0;
			break;
		};
		std::cout << "Insert : I   Remove : R   Rotation : Z" << std::endl << std::endl;
	}
}