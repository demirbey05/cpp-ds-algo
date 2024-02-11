#include <iostream>
#include "include/OLinkedList.h"

int main() {
    OLinkedList<int> list =  OLinkedList<int>();
    list.insert_first(1);
    list.insert_first(2);
    list.insert_first(3);
    list.insert_first(4);
    list.insert_first(5);
    list.delete_first();
    list.delete_at(2);
    list.insert_at(2, 10);
    list.printList();
}
