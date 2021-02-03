//-------------------------------------------------------------------------------------------------------- START OF ArrayClass<DT>
#ifndef __ARRAYCLASS__H
#define __ARRAYCLASS__H
#include "AbstractArrayClass.h"
const int ARRAY_CLASS_DEFAULT_SIZE = 1;
//-------------------------------------------------------------------------------------------------------- Class Defintion
template<typename DataType>
class ArrayClass : virtual public AbstractArrayClass<DataType> {

	friend ostream& operator<< (ostream& s, ArrayClass<DataType>& ac)
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

protected:
	DataType* paObject;
	int _size;
	void copy(const ArrayClass<DataType>& ac);
public:
	ArrayClass(int n);
	ArrayClass();
	ArrayClass(int n, const DataType& val);
	ArrayClass(const ArrayClass<DataType>& ac);
	~ArrayClass();
	int size() const;
	DataType& operator[] (int k);
	void operator= (const ArrayClass<DataType>& ac);
};
//-------------------------------------------------------------------------------------------------------- Constructors / Destructors
template<typename DataType>
ArrayClass<DataType>::ArrayClass(int n)
{
	_size = 0;	// default size in case allocation fails
	paObject = new DataType[n];
	if (paObject == NULL) throw ArrayMemoryException();
	_size = n;
};
template<typename DataType>
ArrayClass<DataType>::ArrayClass()
{
	_size = 0;	// default size in case allocation fails
	paObject = new DataType[ARRAY_CLASS_DEFAULT_SIZE];
	if (paObject == NULL) throw ArrayMemoryException();
	_size = ARRAY_CLASS_DEFAULT_SIZE;
};
template<typename DataType>
ArrayClass<DataType>::ArrayClass(int n, const DataType& val) : ArrayClass(n)
{
	for (int i = 0; i < _size; i++)
		paObject[i] = val;
};
template<typename DataType>
ArrayClass<DataType>::ArrayClass(const ArrayClass<DataType>& ac)
{
	if (&ac != this)
		copy(ac);
};
template<typename DataType>
ArrayClass<DataType>::~ArrayClass()
{
	if (paObject != NULL) delete[] paObject;
	paObject = NULL;
	_size = 0;
};
//-------------------------------------------------------------------------------------------------------- Methods
template<typename DataType>
void ArrayClass<DataType>::copy(const ArrayClass<DataType>& ac) {
	_size = 0;
	paObject = new DataType[ac.size()];
	if (paObject == NULL) throw ArrayMemoryException();
	_size = ac.size();
	for (int i = 0; i < _size; i++)	paObject[i] = ac.paObject[i];
};
template<typename DataType>
int ArrayClass<DataType>::size() const
{
	return _size;
};
template<typename DataType>
DataType& ArrayClass<DataType>::operator[] (int k)
{
	if ((k < 0) || (k >= size())) throw ArrayBoundsException();
	return paObject[k];
};
template<typename DataType>
void ArrayClass<DataType>::operator= (const ArrayClass<DataType>& ac)
{
	if (this != &ac) {
		if (paObject != NULL) delete[] paObject;
		copy(ac);
	}
};

#endif
//-------------------------------------------------------------------------------------------------------- END OF ArrayClass<DT>