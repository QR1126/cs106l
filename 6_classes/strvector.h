//in case mutliple files in a project include strvector, 
//this instruction says only compile this file once!
#ifndef STRVECTOR_H
#define STRVECTOR_H

#include <string>
#include <algorithm>


class StrVector {
    public:
        //type alias (this is how iterator types work!)
        using iterator = std::string*;
        using size_type = size_t;

        //define an initial size for your underlying array
        const size_t kInitialSize = 2;
        
        //constructors and destructor
        StrVector();
        StrVector(size_type size, const std::string& val);
        ~StrVector();

        iterator begin();
        iterator end();

        size_type size() const;
        bool empty() const;

        std::string& operator[](size_type index);
        const std::string& operator[](size_type index) const;
        std::string& at(size_type index);

        iterator insert(iterator pos, const std::string& elem);
        void push_back(const std::string& elem);
        
    private:
    std::string *elements;
    size_type logicalSize;
    size_type allocatedSize;
    void grow();
};

#endif // STRVECTOR_H


