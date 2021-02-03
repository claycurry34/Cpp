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

// Forward Declaration
template<typename DT>
class AbstractArrayClass;
// std::ostream& operator prototype
template<typename DT>
std::ostream& operator<<(std::ostream& s, AbstractArrayClass<DT>& ac);

// AbstractArrayClass defines the operations expected for all implementations of Array data structures.
template<typename DT>
class AbstractArrayClass
{
	friend std::ostream& operator << <DT>(std::ostream& s, AbstractArrayClass<DT>& ac);
public:
	// The number of elements that can be stored by the array
	virtual size_t size() const = NULL;
	// Gets the element at the index
	virtual DT& operator[] (size_t k) = NULL;
};

template<typename DT> std::ostream& operator<< <DT>(std::ostream& s, AbstractArrayClass<DT>& ac)
{
	int n = ac.size() - 1;
	if (n == -1) return s << "{}";
	s << "{";
	for (int i = 0; i < n; i++) s << ac[i] << ",";
	s << ac[n] << "}";
	return s;
}
//---------------------------------------------------------------- END AbstractArrayClass
#endif /* __ABSTRACTARRAY__H */