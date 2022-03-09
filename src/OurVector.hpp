#pragma once

template <typename Vector>
class VectorIterator
{
public:
    using ValueType = typename Vector::ValueType;

public:
    VectorIterator(ValueType* ptr)
    : d_ptr(ptr) {}

public:

    bool operator==(const VectorIterator& rhs) const
    {
        return d_ptr == rhs.d_ptr;
    }

    bool operator!=(const VectorIterator& rhs) const
    {
        return (*this == rhs);
    }
    
    ValueType& operator*()
    {
        return *d_ptr;
    }

    VectorIterator& operator++()
    {
        d_ptr++;
        return *this;
    }

    VectorIterator operator++(int)
    {
        VectorIterator iterator = *this;
        ++(*this);
        return iterator;
    }

    VectorIterator& operator+(int diff)
    {
        d_ptr += diff;
        return *this;
    }

private:
    ValueType* d_ptr;
};

template <typename T>
class OurVector 
{
public:
    // using size_t = unsigned long;
    // using RandomAccessIterator = T*;
    using ValueType = T;
    using Iterator = VectorIterator<OurVector<T>>;

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
    const T &at(size_t) const;
    T &at(size_t);

    T *getArrRaw() const;
    Iterator begin() const 
    {
        return Iterator(d_arr);
    };
    Iterator end() const 
    {
        return Iterator(d_arr + d_size);
    };

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

#include "OurVector.inl"
