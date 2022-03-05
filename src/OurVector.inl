#include "OurVector.hpp"

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
void OurVector<T>::pushBack(T val)
{
    d_arr[d_size] = val;
    d_size++;
}

template <typename T>
T OurVector<T>::at(size_t index)
{
    return d_arr[index];
}
