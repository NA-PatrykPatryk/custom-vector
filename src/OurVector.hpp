#pragma once

template <typename T>
class OurVector 
{
public:
    using size_t = unsigned long;
    using RandomAccessIterator = T*;

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
    void emplaceBack(Args&&... args)
    {
        if(d_size >= d_capacity) {
            reAlloc();
        }

        d_arr[d_size] = T(std::forward<Args>(args)...);
        d_size++;
    }

    void clear();
    const T &at(size_t) const;
    T &at(size_t);

    T *getArrRaw() const;
    T *begin() const;
    T *end() const;

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
