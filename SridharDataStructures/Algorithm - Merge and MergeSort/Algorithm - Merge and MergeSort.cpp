#ifndef __ARRAYCLASS__H
#define __ARRAYCLASS__H
//---------------------------------------------------------------- START OF ArrayClass<DT>
const int ARRAY_CLASS_DEFAULT_SIZE = 1;

// Array
template<typename DT>
class ArrayClass : virtual public AbstractArrayClass<DT> {
protected:
	DT* paObject;
	size_t _size;
	void copy(const ArrayClass<DT>&);
public:
	ArrayClass();
	ArrayClass(size_t);
	ArrayClass(size_t, const DT&);
	ArrayClass(const ArrayClass<DT>&);
	virtual ~ArrayClass();
	virtual size_t size() const;
	virtual DT& operator[] (size_t);
	void operator= (const ArrayClass<DT>&);
};

template<typename DT> void ArrayClass<DT>::copy(const ArrayClass<DT>& ac) {
	paObject = new DT[ac._size];
	if (paObject == NULL) throw ArrayMemoryException();
	_size = ac._size;
	for (int i = 0; i < ac._size; i++)
	{
		paObject[i] = ac.paObject[i];
	}
};
template<typename DT> ArrayClass<DT>::ArrayClass() : paObject(NULL), _size(0)
{
	paObject = new DT[ARRAY_CLASS_DEFAULT_SIZE];
	if (paObject == NULL) throw ArrayMemoryException();
	_size = ARRAY_CLASS_DEFAULT_SIZE;
};
template<typename DT> ArrayClass<DT>::ArrayClass(size_t n)
{
	_size = 0;	// default size in case allocation fails
	paObject = new DT[n];
	if (paObject == NULL) throw ArrayMemoryException();
	_size = n;
};
template<typename DT> ArrayClass<DT>::ArrayClass(size_t n, const DT& val)
{
	_size = 0;	// default size in case allocation fails
	paObject = new DT[n];
	if (paObject == NULL) throw ArrayMemoryException();
	_size = n;
	for (size_t i = 0; i < n; i++)
		paObject[i] = val;	// non-STL types should use a copy constructor
};
template<typename DT> ArrayClass<DT>::ArrayClass(const ArrayClass<DT>& ac) : paObject(NULL), _size(0)
{
	if (&ac != this)
		copy(ac);
};
template<typename DT> ArrayClass<DT>::~ArrayClass()
{
	if (paObject != NULL) delete[] paObject;
	paObject = NULL;
	_size = 0;
};
template<typename DT> size_t ArrayClass<DT>::size() const {
	return _size;
};
template<typename DT> DT& ArrayClass<DT>::operator[] (size_t k)
{
	if ((k < 0) || (k >= _size))
		throw ArrayBoundsException();
	return paObject[k];
};
template<typename DT> void ArrayClass<DT>::operator= (const ArrayClass<DT>& ac)
{
	if (this != &ac) {
		_size = 0;

		if (paObject != NULL)
			delete[] paObject;

		paObject = NULL;

		copy(ac);
	}
};
//---------------------------------------------------------------- END OF ArrayClass<DT>
#endif /* __ARRAYCLASS__H */