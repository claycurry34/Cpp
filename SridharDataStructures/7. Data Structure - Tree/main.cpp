#include "BinaryTree.h"
using namespace std;
int main()
{

	BinaryTree<char> abt1('T', new BinaryTree<char> ('L'), new BinaryTree<char>('R'));

	cout << "Size: " << abt1.size() << ", Height: " << abt1.height() << endl;

	Enumeration<char>* e = abt1.preOrderEnumerator();
	cout << "<";
	while (e->hasMoreElements()) cout << e->nextElement() << " ";
	cout << ">" << endl;
	abt1.display(cout);
	cout << endl;
	abt1.printTree(cout, 1);
}