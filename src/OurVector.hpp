#pragma once

template <typename T>
class OurVector 
{
public:
    using size_t = unsigned long;
public:
    size_t capacity();
    size_t size();
    void pushBack(T );
    T at(size_t );

private:
    size_t d_size {};
    size_t d_capacity{10};
    T* d_arr = new T[d_capacity];
};

#include "OurVector.inl"