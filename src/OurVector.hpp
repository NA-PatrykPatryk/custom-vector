#pragma once

template <typename T>
class OurVector 
{
public:
    using size_t = unsigned long;

public:
    OurVector(int size = 0);
    OurVector(int size, T);
    OurVector(std::initializer_list<T>);
    ~OurVector();

public:
    using RandomAccessIterator = T*;
    size_t capacity();
    size_t size();
    void pushBack(T );
    void popBack();
    T &at(size_t);
    T *getArrRaw() const;
    T *begin() const;
    T *end() const;

private:
    void extendCapacity();

private:
    size_t d_size;
    size_t d_capacity;
    T* d_arr;
};

#include "OurVector.inl"
