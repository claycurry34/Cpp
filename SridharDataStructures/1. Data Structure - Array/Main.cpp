#include "ArrayClass.h"

int main()
{
	ArrayClass<int> ai(5, 4);
	ArrayClass<int> ai2 = ai;
	ArrayClass<int> ai3(10);

	std::cout << ai << std::endl;
	std::cout << ai2 << std::endl;
	std::cout << ai3 << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < ai.size(); i++)
	{
		ai[i] = i * 2;
	}
	try
	{
		ai[5] = 10;
	}
	catch (ArrayBoundsException e)
	{
		e;
		std::cout << "Index out of bounds" << std::endl;
	}
	std::cout << std::endl;
	ai3 = ai;
	std::cout << ai << std::endl;
	std::cout << ai2 << std::endl;
	std::cout << ai3 << std::endl;
}