#include "OurVector.hpp"

// TODO
template <typename T>
using iterator_pointer = typename OurVector<T>::OurVectorIterator::pointer;

template <typename T>
OurVector<T>::OurVectorIterator::OurVectorIterator(pointer ptr)
    : m_ptr{ ptr }
{
}

template <typename T>
typename OurVector<T>::OurVectorIterator::reference OurVector<T>::OurVectorIterator::operator*()
{
    return *m_ptr;
}

template <typename T>
typename OurVector<T>::OurVectorIterator::pointer OurVector<T>::OurVectorIterator::operator->()
{
    return m_ptr;
}

template <typename T>
bool OurVector<T>::OurVectorIterator::operator==(const OurVectorIterator& iter) const
{
    return m_ptr == iter.m_ptr;
}

template <typename T>
bool OurVector<T>::OurVectorIterator::operator!=(const OurVectorIterator& iter) const
{
    return !(*this == iter);
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
typename OurVector<T>::OurVectorIterator& OurVector<T>::OurVectorIterator::operator--()
{
    m_ptr--;
    return *this;
}

template <typename T>
typename OurVector<T>::OurVectorIterator OurVector<T>::OurVectorIterator::operator--(int)
{
    typename OurVector<T>::OurVectorIterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
typename OurVector<T>::OurVectorIterator OurVector<T>::OurVectorIterator::operator+(int offset) const
{
    return m_ptr + offset;
}

template <typename T>
typename OurVector<T>::OurVectorIterator OurVector<T>::OurVectorIterator::operator-(int offset) const
{
    return m_ptr - offset;
}

template <typename T>
bool OurVector<T>::OurVectorIterator::operator<(const OurVectorIterator& iter) const
{
    return *(this->m_ptr) < *(iter.m_ptr);
}

template <typename T>
bool OurVector<T>::OurVectorIterator::operator>(const OurVectorIterator& iter) const
{
    return *(this->m_ptr) > *(iter.m_ptr);
}

template <typename T>
typename OurVector<T>::OurVectorIterator::difference_type OurVector<T>::OurVectorIterator::operator+(const OurVectorIterator& iter) const
{
    return this->m_ptr + iter.m_ptr;
}

template <typename T>
typename OurVector<T>::OurVectorIterator::difference_type OurVector<T>::OurVectorIterator::operator-(const OurVectorIterator& iter) const
{
    return this->m_ptr - iter.m_ptr;
}