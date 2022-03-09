#include "OurVector.hpp"

template <typename T>
OurVector<T>::OurVectorIterator::OurVectorIterator(value_pointer ptr)
    : m_ptr{ ptr }
{
    
}