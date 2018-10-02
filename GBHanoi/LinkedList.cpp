// author: chris-scientist
// created at: 22/09/2018

#include "LinkedList.h"

template<typename U>
LinkedList<U>::LinkedList() : sizeOfList(DEFAULT_SIZE) {
  
}

template<typename U>
void LinkedList<U>::addTop(U aValueItem) {
  ItemLinkedList<U> * addedItem = new ItemLinkedList<U>(aValueItem);
  if(sizeOfList == DEFAULT_SIZE) {
    // S'il n'y a pas d'élément dans la liste
    firstItem = addedItem;
    lastItem = addedItem;
  } else {
    // S'il y a au moins un élément dans la liste
    ItemLinkedList<U> * tmpItem = firstItem;
    firstItem = addedItem;
    tmpItem->setPrevious(firstItem);
    tmpItem->setHasPrevious(true);
    firstItem->setNext(tmpItem);
    firstItem->setHasNext(true);
  }
  sizeOfList++;
}

template<typename U>
U LinkedList<U>::removeTop() {
  ItemLinkedList<U> * item;
  U value;
  if(sizeOfList == DEFAULT_SIZE) {
    // S'il n'y a pas d'élément dans la liste
    return 0;
  } else {
    // S'il y a au mois un élément dans la liste
    item = firstItem;
    value = item->getValue();
    if(item->haveNext()) {
      firstItem = item->getNext();
      firstItem->setHasPrevious(false);
    } else {
      delete lastItem;
    }
    delete item;
  }
  sizeOfList--;
  return value;
}

template<typename U>
U LinkedList<U>::getTop() const {
  if(isEmpty()) {
    return 0;
  }
  return firstItem->getValue();
}

template<typename U>
int LinkedList<U>::getSize() const {
  return sizeOfList;
}

template<typename U>
bool LinkedList<U>::isEmpty() const {
  return (getSize() == DEFAULT_SIZE);
}

template<typename U>
ItemLinkedList<U> * LinkedList<U>::getLastItem() const {
  return lastItem;
}

