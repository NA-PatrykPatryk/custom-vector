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
    OurVectorIterator end() const;
    OurVectorIterator rbegin() const;
    OurVectorIterator rend() const;

public:
    const T& operator[](size_t) const;
    T& operator[](size_t);

private:
    void reAlloc();

private:
    size_t m_size;
    size_t m_capacity;
    T* m_arr;
};

// Iterator
// ________________________________

template <typename T>
class OurVector<T>::OurVectorIterator
{
public:
    using iterator_category = std::random_access_iterator_tag;
    //typedef std::random_access_iterator_tag iterator_category;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
public:
    OurVectorIterator(pointer ptr);
public:
    reference operator*();
    pointer operator->();

    bool operator==(const OurVectorIterator& iter) const;
    bool operator!=(const OurVectorIterator& iter) const;

    OurVectorIterator& operator++();
    OurVectorIterator operator++(int);

    OurVectorIterator& operator--();
    OurVectorIterator operator--(int);

    OurVectorIterator operator+(int offset) const;
    OurVectorIterator operator-(int offset) const;

    bool operator<(const OurVectorIterator& iter) const;
    bool operator>(const OurVectorIterator& iter) const;

private:
    pointer m_ptr{};
};

#include "OurVector.inl"
#include "OurVectorIterator.inl"