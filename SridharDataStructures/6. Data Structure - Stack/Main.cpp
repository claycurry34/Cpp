#include "StackLinked.h"
using namespace std;
//
//// Open Call Stack
//struct AllocationMetrics
//{
//	size_t prev;
//	size_t TAllocated;
//	size_t TFreed;
//
//	size_t CurrentUsage() { return TAllocated - TFreed; }
//};
//static AllocationMetrics s_AllocationMetrics;
//
//void PrintMemoryUsage()
//{
//	int diff = ((int)(s_AllocationMetrics.CurrentUsage())) - ((int)(s_AllocationMetrics.prev));
//	s_AllocationMetrics.prev += diff;
//	std::cout << "Total bytes allocated " << s_AllocationMetrics.CurrentUsage() << std::endl;
//	std::cout << "Difference " << ((diff >= 0) ? "+" : "") << diff << " bytes\n" << std::endl;
//}
//void* operator new(size_t size)
//{
//	s_AllocationMetrics.TAllocated += size;
//	std::cout << "\nAllocating " << size << " bytes\nTotal Allocated: " << s_AllocationMetrics.CurrentUsage() << " bytes" << std::endl;
//
//	return malloc(size);
//}
//void operator delete(void* memory, size_t size)
//{
//	s_AllocationMetrics.TFreed += size;
//	std::cout << "\nFreeing " << size << " bytes\nTotal Allocated: " << s_AllocationMetrics.CurrentUsage() << " bytes" << std::endl;
//	free(memory);
//}





int main()
{
	StackLinked<int> stack;
	try
	{
		for (int i = 0; i < 5; i++) 
		{
			stack.push(i);
			cout << "Pushed " << i << " in the stack" << endl;
		}
		cout << "\nThe stack has " << stack << " as elements pushed into it" << endl;


		StackLinked<int>::iterator t(&stack);

		bool first = true;
		std::cout << "[";
		for (t = stack.begin(); t !=stack.end(); t++)
		{
			if (!first) std::cout << ",";
			first = false;
			std::cout << *t;
		}

		std::cout << "]" << std::endl << std::endl;



		for (int i = 0; i < 6; i++)
			cout << endl << "Popped out " << stack.pop() << " from the stack" << endl;
		cout << endl;
	}
	catch (exception e) { cout << "Exception Thrown\n"; }

}