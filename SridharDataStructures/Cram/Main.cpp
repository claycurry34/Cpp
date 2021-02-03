#include "ArrayClass.h"

class MinHeap
{
public:
	ArrayClass<int> numbers;
	int index;
	MinHeap(int size = 1) : numbers(size), index(0){};
};

int main()
{
	MinHeap h(5);
	std::cout << h.index << " " << h.numbers.size();
}