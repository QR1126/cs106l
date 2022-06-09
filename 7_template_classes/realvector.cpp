#include "realvector.h"

template<class T>
myRealVector<T>::myRealVector()
{
    this->element = new T[init_size];
    this->logical_size = 0;
    this->array_size = init_size;
}

template<class T>
myRealVector<T>::myRealVector(size_t n, const T& val)
{
    this->element = new T[n];
    for (size_t i = 0; i < n; i++) {
        element[i] = val;
    }
    this->logical_size = n;
    this->array_size = init_size;
}

template<class T>
myRealVector<T>::~myRealVector()
{
    delete[] element;
}

template<class T> 
bool myRealVector<T>::empty() const {
    return size() == 0;
}

template<class T>
size_t myRealVector<T>::size() const {
    return this->logical_size;
}

template<class T>
myRealVector<T>::iterator myRealVector<T>::begin() {
    return element;
}

template<class T>
myRealVector<T>::const_iterator myRealVector<T>::cbegin() const{
    return element;
}

template<class T>
myRealVector<T>::iterator myRealVector<T>::end() {
    return element + size();
}

template<class T>
myRealVector<T>::const_iterator myRealVector<T>::cend() const {
    return element + size();
}

template<class T>
T& myRealVector<T>::at(size_t index) {
    return *(begin() + index);
}

template<class T>
void myRealVector<T>::grow() {
    T *new_elem = new T[array_size << 1];
    for (size_t i = 0; i < size(); i++) {
        new_elem[i] = this->element[i];
    }
    delete[] this->element;
    this->element = new_elem;
    this->array_size = array_size * 2;
}

template<class T>
void myRealVector<T>::insert(size_t pos, const T& val) {
    if (logical_size == array_size) {
        grow();
    }
    for(size_t i = logical_size; i != pos; --i){
        this->element[i] = this->element[i-1];
    }
    element[pos] = val;
    logical_size++;
}

template<class T>
void myRealVector<T>::push_back(const T& val) {
    insert(size(), val);
}
