//
// Created by okan on 07.02.2024.
//

#ifndef CPP_DS_OLINKEDLIST_H
#define CPP_DS_OLINKEDLIST_H
#include <iostream>

template<typename T>
class OLNode {
public:

    explicit OLNode(T item_):item(item_),next(nullptr){};
    void setNext(OLNode* next_) { next = next_;};
    OLNode* getNext(){return next;};
    T getItem(){return item;};
    OLNode* move_forward(int i) {
        if (i == 0) {
            return this;
        }
        if(next == nullptr){
            throw std::out_of_range("range is exceeded");
        }else{
            return next->move_forward(i-1);
        }
    }
private:
    T item;
    OLNode* next;
};


template <typename T>
class OLinkedList {
public:
    explicit OLinkedList():head(nullptr),size(0){};
    void insert_first(T elem){
        auto newNode = new OLNode<T>(elem);
        if (head != nullptr){
           newNode->setNext(head);
        }
        head = newNode;
        size++;

    }
    T delete_first(){
        if (size ==0){
            throw std::out_of_range("List is empty");
        }
        T x = head->getItem();
        OLNode<T>* temp = head;
        head = head->getNext();
        delete temp;
        return x;
    }

    T delete_at(int i){
        if (i < 0) { throw std::invalid_argument("i must not below zero");}
        if (i == 0){return delete_first();}
        if (i+1 > size ){
            throw std::out_of_range("range is exceeded");
        }
        OLNode<T>* prev = head->move_forward(i-1);
        T item = prev->getNext()->getItem();
        OLNode<T>* temp = prev->getNext();
        prev->setNext(prev->getNext()->getNext());
        size--;
        delete temp;
        return item;

    }
    void insert_at(int i, T elem ){
        if (i < 0) { throw std::invalid_argument("i must not below zero");}
        if (i==0){
            insert_first(elem);
            return;
        }
        if (i+1 > size) {
            throw std::out_of_range("range is exceeded");
        }

        OLNode<T>* prev = head->move_forward(i-1);
        auto newNode = new OLNode<T>(elem);
        newNode->setNext(prev->getNext());
        prev->setNext(newNode);
        size++;
    }

    OLNode<T>& operator[](int i){
        if (i < 0) { throw std::invalid_argument("i must not below zero");}
        if (i+1 > size){
            throw std::out_of_range("Index out of range");
        }
        return *(head->move_forward(i));
    }
    void printList(){
        OLNode<T>* temp = head;
        while (temp != nullptr){
            std::cout << temp->getItem() << " ";
            temp = temp->getNext();
        }
        std::cout << std::endl;
    }

private:
    OLNode<T> *head;
    size_t size;
};

#endif //CPP_DS_OLINKEDLIST_H
