#pragma once

template <typename T>
class OurVector 
{
public:
    using size_t = unsigned long;
public:
    size_t capacity();
    size_t size();

private:
    size_t d_size {};
    size_t d_capacity{10};
};

#include "OurVector.inl"