#pragma once
#include <iterator>

template <typename T>
class OurVector
{
public:
    // Iterator is a nested class
    class OurVectorIterator;
public:
    OurVector(int size = 0);
    OurVector(int size, T);
    OurVector(std::initializer_list<T>);
    ~OurVector();

public:
    size_t capacity();
    size_t size();
    void shrinkToSize();

    void pushBack(T);
    void popBack();

    template <typename... Args>
    void emplaceBack(Args&&... args);

    void clear();
    const T& at(size_t) const;
    T& at(size_t);

    T* getArrRaw() const;
    OurVectorIterator begin() const;
    T* end() const;

public:
    const T& operator[](size_t) const;
    T& operator[](size_t);

private:
    void reAlloc();

private:
    size_t d_size;
    size_t d_capacity;
    T* d_arr;
};

// Iterator
// ________________________________

template <typename T>
class OurVector<T>::OurVectorIterator
{
public:
    using iterator_category = std::random_access_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using value_pointer = T*;
    using value_reference = T&;
public:
    OurVectorIterator(value_pointer ptr);
public:
    value_reference operator*();
    value_pointer operator->();

    bool operator==(const OurVectorIterator& iter) const;
    bool operator!=(const OurVectorIterator& iter) const;

    OurVectorIterator& operator++();
    OurVectorIterator operator++(int);

    OurVectorIterator& operator--();
    OurVectorIterator operator--(int);

    OurVectorIterator operator+(int offset);
    OurVectorIterator operator-(int offset);

private:
    value_pointer m_ptr{};
};

#include "OurVector.inl"
#include "OurVectorIterator.inl"