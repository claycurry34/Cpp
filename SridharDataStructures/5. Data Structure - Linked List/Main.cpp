#include "LinkedList.h"
#include "StringClass.h"

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



int main() {

	const char* movies[] = { "'2001'", "'Tron'", "'Wargames'", "'Robocop'", "'Outland'", "'Colossus'", "'Alien'" };

	LinkedList<const char*> L("'2002'");	// adds 0 bytes

	try
	{
		for (int i = 0; i < 7; i++) {	// adds 200 bytes
			L.insertAt(movies[i], i);
		}
	}
	catch (LinkedListException e) {
		e;
		std::cout << "This couldn't happen" << std::endl;
	}

	LinkedList<const char*>::iterator t;


	bool first = true;
	std::cout << "[";
	for (t = L.begin(); t != L.end(); t++)
	{
		if (!first) std::cout << ",";
		first = false;
		std::cout << *t;
	}
	
	std::cout << "]" << std::endl<< std::endl;


	L.removeAt(4);
	std::cout << L << std::endl ;

	
	try {
		while (!L.isEmpty()) 
		{ 
			L.remove(); 	
		}
	}
	catch (LinkedListBounds e) {
		e;
		std::cout << "This couldn't happen" << std::endl;
	}try {
		L.remove();
	}
	catch (LinkedListBounds e) {
		e;
		std::cout << "Tried to delete non-existent node" << std::endl;
	}
	std::cout << L << std::endl;

}