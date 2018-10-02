// author: chris-scientist
// created at: 22/09/2018
// updated at: 26/09/2018
// description: liste doublement chainée

#ifndef LINKEDLIST
#define LINKEDLIST

#include "ItemLinkedList.cpp"

template<typename U>
class LinkedList {
  private:
    ItemLinkedList<U> * firstItem;
    ItemLinkedList<U> * lastItem;
    int sizeOfList;
    static const int DEFAULT_SIZE = 0;
  public:
    LinkedList();
    void addTop(U aValueItem);
    U removeTop();
    U getTop() const;
    int getSize() const;
    bool isEmpty() const;
    ItemLinkedList<U> * getLastItem() const;
};

#endif

