#include "OurVector.hpp"

template <typename T>
OurVector<T>::OurVectorIterator::OurVectorIterator(value_pointer ptr)
    : m_ptr{ ptr }
{

}

template <typename T>
typename OurVector<T>::OurVectorIterator::value_reference OurVector<T>::OurVectorIterator::operator*()
{
    return *m_ptr;
}

template <typename T>
typename OurVector<T>::OurVectorIterator::value_reference OurVector<T>::OurVectorIterator::operator->()
{
    return m_ptr;
}

template <typename T>
typename OurVector<T>::OurVectorIterator& OurVector<T>::OurVectorIterator::operator++()
{
    m_ptr++;
    return *this;
}

template <typename T>
typename OurVector<T>::OurVectorIterator OurVector<T>::OurVectorIterator::operator++(int)
{
    typename OurVector<T>::OurVectorIterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename Ta>
bool operator==(const typename OurVector<Ta>::OurVectorIterator& iter1,
                const typename OurVector<Ta>::OurVectorIterator& iter2)                           
{
    return iter1.m_ptr == iter2.m_ptr;
}

template <typename Ta>
bool operator!=(const typename OurVector<Ta>::OurVectorIterator& iter1,
                const typename OurVector<Ta>::OurVectorIterator& iter2)                           
{
    return !(iter1 == iter2);
}