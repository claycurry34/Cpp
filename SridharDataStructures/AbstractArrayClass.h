#ifndef __ABSTRACTARRAY__H
#define __ABSTRACTARRAY_H
//---------------------------------------------------------------- START AbstractArrayClass
#include <iostream>
#include <exception>
// Base Exception Class for all ArrayClass-type Exceptions
class ArrayException : public std::exception {};
// Allocation of free store using "new" failed.
class ArrayMemoryException : public ArrayException {};
// Element could not be accessed outside the bounds of the array
class ArrayBoundsException : public ArrayException {};

// AbstractArrayClass defines the operations expected for all implementations of Array data structures.
template<typename DT>
class AbstractArrayClass
{
	friend std::ostream& operator<< (std::ostream& s, AbstractArrayClass<DT>& ac)
	{
		size_t n = ac.size() - 1;
		if (n == -1) return s << "{}";
		s << "{";
		for (int i = 0; i < n; i++) s << ac[i] << ",";
		s << ac[n] << "}";
		return s;
	}
public:
	// The number of elements that can be stored by the array
	virtual size_t size() const = NULL;
	// Gets the element at the index
	virtual DT& operator[] (size_t k) = NULL;
};

//---------------------------------------------------------------- END AbstractArrayClass
#endif /* __ABSTRACTARRAY__H */
