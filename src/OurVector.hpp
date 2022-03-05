#pragma once

template <typename T>
class OurVector 
{
public:
    using size_t = unsigned long;

public:
    OurVector(int size = 0);
    OurVector(int size, T);
    ~OurVector();

public:
    size_t capacity();
    size_t size();
    void pushBack(T );
    void popBack();
    void extendCapacity();
    T at(size_t );
    T *getArrRaw() const;

private:
    size_t capacityBase{ 10 };
    double capacityMultiplicator{ 1.5 };
    size_t d_size{};
    size_t d_capacity{};
    T* d_arr{ nullptr };
};

#include "OurVector.inl"
