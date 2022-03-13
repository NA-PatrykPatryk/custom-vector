#include "OurVector.hpp"

template <typename T>
OurVector<T>::OurVector(int size)
    : m_size{ static_cast<size_t>(size) }
    , m_capacity{ m_size }
{
    if (size < 0)
    {
        throw std::invalid_argument{ "Invalid argument provided" };
    }

    m_arr = new T[m_capacity];
}

template <typename T>
OurVector<T>::OurVector(int size, T value)
    : OurVector(size)
{
    for (size_t i = 0; i < (size_t)size; i++) {
        m_arr[i] = value;
    }
}

template <typename T>
OurVector<T>::OurVector(std::initializer_list<T> list)
    : m_size{ list.size() }
    , m_capacity{ m_size }
    , m_arr{ new T[m_capacity] }
{
    int i{ 0 };
    for (auto x : list)
    {
        m_arr[i] = x;
        ++i;
    }
}

template <typename T>
OurVector<T>::~OurVector() {
    delete[] m_arr;
}

template <typename T>
size_t OurVector<T>::size()
{
    return m_size;
}

template <typename T>
size_t OurVector<T>::capacity()
{
    return m_capacity;
}

template <typename T>
void OurVector<T>::reAlloc() {
    size_t newCapacity{};
    if (m_capacity) {
        newCapacity = m_capacity * 2;
    }
    else {
        newCapacity = 1;
    }

    T* tempArr = new T[newCapacity];

    for (size_t i = 0; i < m_size; i++) {
        tempArr[i] = std::move(m_arr[i]);
    }
    delete[] m_arr;

    m_arr = tempArr;
    m_capacity = newCapacity;
}

template <typename T>
void OurVector<T>::pushBack(T val)
{
    if (m_size >= m_capacity) {
        reAlloc();
    }

    m_arr[m_size] = std::move(val);
    m_size++;
}

template <typename T>
void OurVector<T>::popBack()
{
    if (m_size > 0)
        --m_size;
}

template <typename T>
template <typename... Args>
void OurVector<T>::emplaceBack(Args&&... args)
{
    if (m_size >= m_capacity) 
    {
        reAlloc();
    }

    m_arr[m_size] = T(std::forward<Args>(args)...);
    m_size++;
}

template <typename T>
void OurVector<T>::insert(OurVectorIterator& insertIterator, T value)
{
    if (m_size >= m_capacity) 
    {
        m_capacity *= 2;
    }

    T* tempArr = new T[m_capacity];

    int i {0};
    auto it = begin();
    for (; it != insertIterator; ++it, ++i)
    {
        tempArr[i] = m_arr[i];
    }

    tempArr[i] = std::move(value);
    insertIterator = &(tempArr[i]);

    for (; it != end(); ++it, ++i)
    {
        tempArr[i + 1] = m_arr[i];
    }

    delete[] m_arr;
    m_arr = tempArr;
}

template <typename T>
void OurVector<T>::erase(OurVectorIterator& iterator)
{
    while(iterator != end())
    {
        *iterator = *(iterator + 1);;
        ++iterator;
    }
    iterator = nullptr;
    --m_size;
}

template <typename T>
T* OurVector<T>::getArrRaw() const
{
    return m_arr;
}

template <typename T>
typename OurVector<T>::OurVectorIterator OurVector<T>::begin() const
{
    return OurVectorIterator(m_arr);
}

template <typename T>
typename OurVector<T>::OurVectorIterator OurVector<T>::end() const
{
    return OurVectorIterator(m_arr + m_size);
}

template <typename T>
typename OurVector<T>::OurVectorIterator OurVector<T>::rbegin() const
{
    return OurVectorIterator(end() - 1);
}

template <typename T>
typename OurVector<T>::OurVectorIterator OurVector<T>::rend() const
{
    return OurVectorIterator(begin() - 1);
}

template <typename T>
void OurVector<T>::clear() {
    m_size = 0;
}

template <typename T>
const T& OurVector<T>::at(size_t index) const
{
    if (index >= m_size)
    {
        throw std::out_of_range("vector index out of bound");
    }

    return m_arr[index];
}

template <typename T>
T& OurVector<T>::at(size_t index)
{
    if (index >= m_size)
    {
        throw std::out_of_range("vector index out of bound");
    }

    return m_arr[index];
}

template <typename T>
const T& OurVector<T>::operator[](size_t index) const
{
    return m_arr[index];
}

template <typename T>
T& OurVector<T>::operator[](size_t index)
{
    return m_arr[index];
}

template <typename T>
void OurVector<T>::shrinkToSize() {
    m_capacity = m_size;
}