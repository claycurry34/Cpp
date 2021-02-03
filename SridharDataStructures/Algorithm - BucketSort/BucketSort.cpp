#include "ArrayClass.h"


ArrayClass<int> bucketSort(ArrayClass<int>& ac, int max) 
{
	ArrayClass<int> bucket(max + 1);
	int i;
	for (i = 0; i < max + 1; i++) { bucket[i] = 0; }
	for (i = 0; i < ac.size(); i++) { bucket[ac[i]] = 1; }
	return bucket;
}

int main() 
{
	int ints[] = { 8, 11, 4, 30, 22, 10, 15, 3, 7, 29 };
	ArrayClass<int> aInts(10);
	
	for (int i = 0; i < 10; i++) 
	{
		aInts[i] = ints[i];
	}

	cout << "The initial sample values are " << endl;
	cout << aInts << endl;

	ArrayClass<int> bucket = bucketSort(aInts, 30);

	for (int i = 0; i < 31; i++)
	{
		if (bucket[i] > 0) cout << i << ", ";
	}
}