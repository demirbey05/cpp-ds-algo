//
// Created by okan on 04.02.2024.
//

#ifndef CPP_DS_OVEC_H
#define CPP_DS_OVEC_H

#include<iostream>

template<typename T>
class OVec{
public:

    ~OVec() {
        delete [] elems;
    }

    explicit OVec(int sz):capacity(sz),size(0){ elems = new T[sz];}

    inline size_t len() const {return size;}
    inline size_t cap() const {return capacity;}

    inline T& operator[](int i) const {
        if (i+1 > size){
            throw
        }
        return elems[i];
    }






private:
    T* elems;
    size_t size;
    size_t capacity;



};






#endif //CPP_DS_OVEC_H
