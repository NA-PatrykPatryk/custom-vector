#include "OurVector.hpp"


template <typename T>
OurVector<T>::~OurVector(){
    delete [] d_arr;
}
    

template <typename T>
OurVector<T>::OurVector(size_t size)
    : d_size{ size }
    , d_capacity{ static_cast<size_t>(size * capacityMultiplicator + capacityBase) }
    , d_arr{ new T[d_capacity] }
{
}

template <typename T>
OurVector<T>::OurVector(size_t size, T value)
    : OurVector(size)
{
    for(size_t i = 0; i < size; i++) {
        d_arr[i] = value;
    }
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
void OurVector<T>::pushBack(T val)
{

    if(d_size>=d_capacity)
    {
        
       T* tempArr = new T[static_cast<size_t>(d_capacity* capacityMultiplicator)];
       for (size_t i = 0; i < d_size; i++)
       {
           tempArr[i] = d_arr[i];
       }
       delete [] d_arr;  
       d_capacity*=capacityMultiplicator;
       d_arr = tempArr;
    }
    d_arr[d_size] = val;
    d_size++;
}

template <typename T>
T OurVector<T>::at(size_t index)
{
    if(index>=d_size)
    {
        throw std::out_of_range("vector index out of bound");
    }

    return d_arr[index];
}

