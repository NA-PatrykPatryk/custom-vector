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
typename OurVector<T>::OurVectorIterator::value_pointer OurVector<T>::OurVectorIterator::operator->()
{
    return m_ptr;
}

template <typename T>
bool OurVector<T>::OurVectorIterator::operator==(const OurVectorIterator& rhs) const
{
    return m_ptr == rhs.m_ptr;
}

template <typename T>
bool OurVector<T>::OurVectorIterator::operator!=(const OurVectorIterator& rhs) const
{
    return (*this == rhs);
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

template <typename T>
typename OurVector<T>::OurVectorIterator OurVector<T>::OurVectorIterator::operator+(int offset)
{
    return m_ptr + offset;
}

template <typename T>
typename OurVector<T>::OurVectorIterator OurVector<T>::OurVectorIterator::operator-(int offset)
{
    return m_ptr - offset;
}