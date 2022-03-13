#include "OurVector.hpp"

#define ITERATOR OurVector<T>::OurVectorIterator

template <typename T>
ITERATOR::OurVectorIterator(pointer ptr)
    : m_ptr{ ptr }
{
}

template <typename T>
typename ITERATOR::reference ITERATOR::operator*()
{
    return *m_ptr;
}

template <typename T>
typename ITERATOR::pointer ITERATOR::operator->()
{
    return m_ptr;
}

template <typename T>
bool ITERATOR::operator==(const OurVectorIterator& iter) const
{
    return m_ptr == iter.m_ptr;
}

template <typename T>
bool ITERATOR::operator!=(const OurVectorIterator& iter) const
{
    return !(*this == iter);
}

template <typename T>
typename ITERATOR& ITERATOR::operator++()
{
    m_ptr++;
    return *this;
}

template <typename T>
typename ITERATOR ITERATOR::operator++(int)
{
    typename ITERATOR tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
typename ITERATOR& ITERATOR::operator--()
{
    m_ptr--;
    return *this;
}

template <typename T>
typename ITERATOR ITERATOR::operator--(int)
{
    typename ITERATOR tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
typename ITERATOR ITERATOR::operator+(int offset) const
{
    return m_ptr + offset;
}

template <typename T>
typename ITERATOR ITERATOR::operator-(int offset) const
{
    return m_ptr - offset;
}

template <typename T>
bool ITERATOR::operator<(const OurVectorIterator& iter) const
{
    return *(this->m_ptr) < *(iter.m_ptr);
}

template <typename T>
bool ITERATOR::operator>(const OurVectorIterator& iter) const
{
    return *(this->m_ptr) > *(iter.m_ptr);
}

template <typename T>
typename ITERATOR::difference_type ITERATOR::operator+(const OurVectorIterator& iter) const
{
    return this->m_ptr + iter.m_ptr;
}

template <typename T>
typename ITERATOR::difference_type ITERATOR::operator-(const OurVectorIterator& iter) const
{
    return this->m_ptr - iter.m_ptr;
}