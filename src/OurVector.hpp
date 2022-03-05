#pragma once

template <typename T>
class OurVector 
{
public:
    using size_t = unsigned long;

public:
    OurVector(size_t size = 0);

public:
    size_t capacity();
    size_t size();
    void pushBack(T );
    T at(size_t );

private:
    size_t capacityBase{ 10 };
    double capacityMultiplicator{ 1.5 };
    size_t d_size{};
    size_t d_capacity{};
    T* d_arr{};
};

#include "OurVector.inl"