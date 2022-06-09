#ifndef myRealVector_H
#define myRealVector_H

#include <string>
#include <algorithm>
#include "realvector.h"

template<class T> class myRealVector {
public:
    using iterator = T*;
    using const_iterator = const T*;

    const size_t init_size = 2;

    myRealVector();
    ~myRealVector();
    myRealVector(size_t n, const T& val);

    bool empty() const;
    size_t size() const;

    iterator begin();
    iterator end();

    T& at(size_t index);

    void insert(size_t pos, const T& val);
    void push_back(const T& val);

    const_iterator cbegin() const;
    const_iterator cend() const;


private:
    void grow();
    T *element;
    size_t logical_size;
    size_t array_size;
};

#endif
