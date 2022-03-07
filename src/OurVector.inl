#include "OurVector.hpp"

template <typename T>
OurVector<T>::OurVector(int size)
    : d_size{static_cast<size_t>(size)}
    , d_capacity{d_size}
{
    if (size < 0)
    {
        throw std::invalid_argument{"Invalid argument provided"};
    }
    
    d_arr = new T[d_capacity];
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
OurVector<T>::OurVector(std::initializer_list<T> list) 
    : d_size{list.size()},
    d_capacity{d_size},
    d_arr{new T[d_capacity]}
{
    int i {0};
    for (auto x : list) {
        d_arr[i] = x;
        ++i;
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
    size_t newCapacity {};
    if (d_capacity) {
        newCapacity = d_capacity * 2;
    } else {
        newCapacity = 1;
    }

    T* tempArr = new T[newCapacity];

    for (size_t i = 0; i < d_size; i++) {
        tempArr[i] = std::move(d_arr[i]);
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

    d_arr[d_size] = std::move(val);
    d_size++;
}

template <typename T>
void OurVector<T>::popBack()
{
    if(d_size > 0)
        --d_size;
}

template <typename T>
T *OurVector<T>::getArrRaw() const 
{
	return d_arr;
}

template <typename T>
T *OurVector<T>::begin() const 
{
	return d_arr;
}

template <typename T>
T *OurVector<T>::end() const 
{
	return d_arr + d_size;
}

template <typename T>
const T &OurVector<T>::at(size_t index) const
{
    if(index >= d_size)
    {
        throw std::out_of_range("vector index out of bound");
    }

    return d_arr[index];
}

template <typename T>
T &OurVector<T>::at(size_t index)
{
    if(index >= d_size)
    {
        throw std::out_of_range("vector index out of bound");
    }

    return d_arr[index];
}

template <typename T>
const T &OurVector<T>::operator[](size_t index) const
{
    return d_arr[index];
}