// author: chris-scientist
// created at: 20/09/2018
// updated at: 22/09/2018

#include "ItemLinkedList.h"

template<typename T>
ItemLinkedList<T>::ItemLinkedList(T aValue) : value(aValue), hasPrevious(false), hasNext(false) {
  
}

template<typename T>
T ItemLinkedList<T>::getValue() const {
  return value;
}

template<typename T>
bool ItemLinkedList<T>::havePrevious() const {
  return hasPrevious;
}

template<typename T>
bool ItemLinkedList<T>::haveNext() const {
  return hasNext;
}

template<typename T>
void ItemLinkedList<T>::setHasPrevious(bool _hasPrevious) {
  hasPrevious = _hasPrevious;
}

template<typename T>
void ItemLinkedList<T>::setHasNext(bool _hasNext) {
  hasNext = _hasNext;
}

template<typename T>
ItemLinkedList<T> * ItemLinkedList<T>::getPrevious() const {
  return previous;
}

template<typename T>
ItemLinkedList<T> * ItemLinkedList<T>::getNext() const {
  return next;
}

template<typename T>
void ItemLinkedList<T>::setPrevious(ItemLinkedList<T> * anItem) {
  previous = anItem;
}

template<typename T>
void ItemLinkedList<T>::setNext(ItemLinkedList<T> * anItem) {
  next = anItem;
}

