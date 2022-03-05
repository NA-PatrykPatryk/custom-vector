#include "OurVector.hpp"


template <typename T>
OurVector<T>::OurVector(int size) :
	d_size{ size >= 0? (size_t)size : (size_t)0 },
	d_capacity{ static_cast<size_t>(size * capacityMultiplicator + capacityBase) },
	d_arr{ new T[d_capacity] }
{
}

template <typename T>
OurVector<T>::OurVector(int size, T value)
    : OurVector(size)
{
    for(size_t i = 0; i < (size_t)size; i++) {
        d_arr[i] = value;
    }
}

template <typename T>
OurVector<T>::~OurVector(){
    delete [] d_arr;
}

template <typename T>
size_t OurVector<T>::size() 
{
    return d_size;
}

template <typename T>
size_t OurVector<T>::capacity()
{
    return d_capacity;
}

template <typename T>
void OurVector<T>::extendCapacity() {
       const auto newCapacity = static_cast<size_t>(d_capacity * capacityMultiplicator);
       T* tempArr = new T[newCapacity];

       for (size_t i = 0; i < d_size; i++) {
           tempArr[i] = d_arr[i];
       }
       delete [] d_arr;  

       d_arr = tempArr;
       d_capacity = newCapacity;
}

template <typename T>
void OurVector<T>::pushBack(T val)
{
    if(d_size>=d_capacity) {
	    extendCapacity();
    }
    d_arr[d_size] = val;
    d_size++;
}

template <typename T>
void OurVector<T>::popBack()
{
    if(d_size > 0)
        --d_size;
}

template <typename T>
T *OurVector<T>::getArrRaw() const {
	return d_arr;
}

template <typename T>
T OurVector<T>::at(size_t index)
{
    if(index >= d_size)
    {
        throw std::out_of_range("vector index out of bound");
    }

    return d_arr[index];
}
