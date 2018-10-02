// author: chris-scientist
// created at: 20/09/2018
// updated at: 22/09/2018
// description: élément d'une liste doublement chaînée

#ifndef ITEMLINKEDLIST
#define ITEMLINKEDLIST

template<typename T>
class ItemLinkedList {
  private:
    T value;
    bool hasPrevious;
    bool hasNext;
    ItemLinkedList<T> * previous;
    ItemLinkedList<T> * next;
  public:
    ItemLinkedList(T aValue);
    T getValue() const;
    bool havePrevious() const;
    bool haveNext() const;
    void setHasPrevious(bool _hasPrevious);
    void setHasNext(bool _hasNext);
    ItemLinkedList<T> * getPrevious() const;
    ItemLinkedList<T> * getNext() const;
    void setPrevious(ItemLinkedList<T> * anItem);
    void setNext(ItemLinkedList<T> * anItem);
};

#endif

