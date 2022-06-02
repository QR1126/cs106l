//dont forget to include the .h file!
//implementation for strvector.cpp goes here!

#include "strvector.h"

StrVector::StrVector() : logicalSize(0), allocatedSize(kInitialSize) {
    this->elements = new std::string[allocatedSize];
}

StrVector::StrVector(size_type size, const std::string& val) : 
    logicalSize(size), allocatedSize(size << 1) {
    this->elements = new std::string[allocatedSize];
}

StrVector::~StrVector() {
    delete[] elements;
}

StrVector::size_type StrVector::size() const{
    return logicalSize;
}

bool StrVector::empty() const {
    return logicalSize == 0;
}

StrVector::iterator StrVector::begin() {
    return elements;
}

StrVector::iterator StrVector::end() {
    return elements + size();
}

std::string& StrVector::operator[](size_type index) {
    return *(begin() + index);
}

std::string& StrVector::at(size_type index) {
    if (index >= size() || index < 0) {
        throw std::out_of_range("index is illegal!");
    }
    return *(begin() + index);
}

void StrVector::grow() {
    iterator new_elems = new std::string[allocatedSize << 1];
    std::copy(begin(), end(), new_elems);
    delete[] this->elements;
    this->elements = new_elems;
    allocatedSize *= 2;
}

StrVector::iterator StrVector::insert(iterator pos, const::std::string& elem) {
    size_type index = pos - begin();
    if (size() == allocatedSize) {
        grow();
    }
    pos = index + begin();
    std::copy_backward(pos, end(), end() + 1);
    *pos = elem;
    ++logicalSize;
    return pos;
}

void StrVector::push_back(const std::string& elem) {
    insert(end(), elem);
}



