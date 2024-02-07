//
// Created by okan on 07.02.2024.
// Static Array Implementation

#ifndef CPP_DS_OSTARRAY_H
#define CPP_DS_OSTARRAY_H
#include <iostream>

template<typename T>
class OStArray {
public:

    // Destructor
    ~OStArray() {
        delete [] elems;
    }
    // Standard constructor
    explicit OStArray(int sz):size(sz){ elems = new T[sz];}

    // Copy Assignment
    OStArray& operator=(const OStArray& other){
        if (this != &other){
            delete [] elems;
            size = other.size;
            elems = new T[size];
            for (int i = 0; i < size; i++){
                elems[i] = other.elems[i];
            }
        }
        return *this;
    }

    //  Move Assignemnt
    OStArray& operator=(OStArray&& other) noexcept {
        if (this != &other){
            delete [] elems;
            size = other.size;
            elems = other.elems;
            other.elems = nullptr;
            other.size = 0;
        }
        return *this;
    }

    // Copy Constructor
    OStArray(const OStArray& other) {
        if (this != &other){
            delete [] elems;
            size = other.size;
            elems = new T[size];
            for (int i = 0; i < size; i++){
                elems[i] = other.elems[i];
            }
        }
    }

    // Move Constructor
    OStArray(OStArray&& other) noexcept {
        if (this != &other){
            delete [] elems;
            size = other.size;
            elems = other.elems;
            other.elems = nullptr;
            other.size = 0;
        }
    }

    T& operator[](int i) const {
        if (i+1 > size){
            throw std::out_of_range("Index out of range");
        }
        return elems[i];
    }

    inline size_t len() const {return size;}

    void insert_at(int i, const T& elem){
        if (i+1 > size || i < 0){
            throw std::out_of_range("Index out of range");
        }
        OStArray<T> temp(size+1);
        copy_forward(0,i, temp, 0);
        temp.elems[i] = elem;
        copy_forward(i, size-i, temp, i+1);

        *this = std::move(temp);
    }
    T& delete_at(int i){
        if(i+1 > size || i < 0 ){
            throw std::out_of_range("Index out of range");
        }
        OStArray<T> temp(size -1);
        copy_forward(0,i,temp,0);
        T ret = elems[i];
        copy_forward(i+1,size-i-1,temp,i);

        *this = std::move(temp);

        return ret;

    }

    void insert_first(T& elem) {
        insert_at(0,elem);
    }
    void insert_last(T& elem) {
        insert_at(size-1, elem);
    }
    T& delete_first(){
        T ret = delete_at(0);
        return ret;
    }
    T& delete_last(){
        T ret = delete_at(size-1);
        return ret;
    }

private:
    T* elems;
    size_t size;

    void copy_forward(int i, int n, OStArray& other, int j){
        if (i + n > size || j + n > other.size){
            throw std::out_of_range("Index out of range");
        }
        for (int k= 0;k<n;k++){
            other.elems[j+k] = elems[i+k];
        }
    }
};



#endif //CPP_DS_OSTARRAY_H
