#pragma once

template <typename T>
class OurVector 
{
public:
    using size_t = unsigned long;
public:
    size_t size();

private:
    size_t d_size {};
};

#include "OurVector.inl"