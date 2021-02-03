/* Primitive operations for all arrays include:
 *  - create(n)                // creates an array of size n
 *
 *  - putObject(newObject, i)  // places an object, newObject, at index position i
 *
 *  - getObject(i)             // gets the object at index position k
 *
 *  - size()                   // returns the integer number of elements which can be accommodated in the array
 */

 //-------------------------------------------------------------------------------------------------------- START OF AbstractArrayClass<DT>
#ifndef __ABSTRACTARRAY_H
#define __ABSTRACTARRAY_H

#include <iostream>
using namespace std;
//-------------------------------------------------------------------------------------------------------- Class Defintion
class Exception {};
class ArrayException : public Exception {};             // General exception type for all array-type errors
class ArrayMemoryException : public ArrayException {};  // allocation using "new" failed 
class ArrayBoundsException : public ArrayException {};  // attempted to access memory oustide the array

template<typename DataType>
class AbstractArrayClass
{
	friend ostream& operator<< (ostream& s, AbstractArrayClass<DataType>& ac);
protected:
	//DataType* paObject;                 // contains a list of fixed pointers to DTs stored sequentially in memory
								  // pointers cannot be changed, but the objects being pointed to can change
	//int _size;                    // holds number of elements which can be accommodated in the array
public:
	virtual int size() const = NULL;		// arrays must impliment size(), which returns the greatest possible number of elements that the array can hold.
	virtual DataType& operator[] (int k) = NULL;	// accesses and returns the element at a specified index.
// The [] operator replaces the following methods:
	//	void putObject (DataType newObject, int k);
	//	DataType getObject (int k);
};
//-------------------------------------------------------------------------------------------------------- Methods
template<typename DataType> ostream& operator<< (ostream& s, AbstractArrayClass<DataType>& ac)
{
	int iter = 0;
	s << "[";
	while (iter < ac.size())
	{
		if (iter > 0)
			s << ",";
		s << ac[iter];
		iter += 1;
	}
	return s << "]";
};
#endif
//-----------------------------------------------------------------------------------------