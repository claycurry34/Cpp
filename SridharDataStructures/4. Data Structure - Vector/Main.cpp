#include "Vector.h"

int main()
{
	Vector<int> v;
	cout << v << ",cap " << v.capacity() << endl;
	for (int i = 0; i < 5; i++)
	{
		v.add(5 * i);
		cout << v << ",cap " << v.capacity() << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		v.insert(-5 * i, 2 * i);
		cout << v << ",cap " << v.capacity() << endl;
	}
	for (int i = 4; i >= 0; i--)
	{
		v.remove(i * 2);
		cout << v << ",cap " << v.capacity() << endl;
	}
	for (int i = 4; i >= 0; i--)
	{
		v.remove(i);
		cout << v << ",cap " << v.capacity() << endl;
	}
}