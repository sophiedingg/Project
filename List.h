// Project UID c1f28c309e55405daf00c565d57ff9ad

#ifndef LIST_H
#define LIST_H
/* List.h
 *
 * doubly-linked, double-ended list with Iterator interface
 * Project UID c1f28c309e55405daf00c565d57ff9ad
 * EECS 280 Project 4
 */

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL


template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:
  List();

  ~List();

  List(const List& other);

  List & operator=(const List& rhs);
  
  //EFFECTS:  returns true if the list is empty
  bool empty() const;

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
  int size() const;

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front();

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back();

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum);

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum);

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front();

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back();

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear();

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists

private:
  //a private type
  int length; // creates size variable
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other);

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty

public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.

    

  public:
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
    Iterator& operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }

    Iterator(): node_ptr(nullptr) {}

    T& operator*() {
      return node_ptr->datum;
    }

    Iterator& operator++(){
      assert(node_ptr);
      node_ptr = node_ptr->next;
      return *this;
    }

    bool operator==(const Iterator & rhs) const {
      return node_ptr == rhs.node_ptr;
    }

    bool operator!=(const Iterator & rhs) const {
      return node_ptr != rhs.node_ptr;
    }  

  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here
    friend class List<T>;

    // construct an Iterator at a specific position
    Iterator(Node *p): node_ptr(p) {}
    // Iterator(Node *p);
    // is this a copy constructor of a default constructor?

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  }

  // return an Iterator pointing to "past the end"
  Iterator end() const {
    return nullptr;
  }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
  void erase(Iterator i);

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
  void insert(Iterator i, const T &datum);

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.

template<typename T>
bool List<T>::empty() const {
  if (length == 0) {
    return true;
  }
  return false;
}

template<typename T> 
int List<T>::size() const {
  return length;
}

template<typename T>
T & List<T>::front() {
  assert(!empty());
  return first->datum;
}

template<typename T>
T & List<T>::back() {
  assert(!empty());
  return last->datum;
}

template<typename T>
void List<T>::push_front(const T &datum) {
  Node *p = new Node;
  p->datum = datum;
  p->prev = nullptr;
  if (empty()) {
    first = last = p;
    p->next = nullptr;
  }
  else {
    first->prev = p;
    p->next = first;
    first = p;
  }
  length++;
}

template<typename T>
void List<T>::push_back(const T &datum) {
  Node *p = new Node;
  p->datum = datum;
  p->next = nullptr;
  if (empty()) {
    first = last = p;
    first->prev = nullptr;
  }
  else {
    last->next = p;
    p->prev = last;
    last = p;
  }
  length++;
}

template<typename T>
void List<T>::pop_front() {
  assert(!empty());
  if (length == 1) {
    
    delete first;
    first = last = nullptr;
  }
  else if (length == 2) {
    Node *victim = first;
    first = last;
    last->prev = nullptr;
    delete victim;
  }
  else {
    Node *victim = first;
    first = first->next;
    first->prev = nullptr;
    delete victim;
  }
  length--;
}

template<typename T>
void List<T>::pop_back() {
  assert(!empty());
  if (length == 1) {
    
    delete first;
    first = last = nullptr;
  }
  else if (length == 2) {
    Node *victim = last;
    last = first;
    first->next = nullptr;
    delete victim;
  }
  else {
    Node *victim = last;
    last = last->prev;
    last->next = nullptr;
    delete victim;
    length--;
  }
}

template<typename T>
void List<T>::clear() {
  while (!empty()) {
    pop_front();
  }
}

template<typename T>
void List<T>::copy_all(const List<T> &other){
  if (other.empty()) {
    first = last = nullptr;
  }
  for (Node *ptr = other.first; ptr != nullptr; ptr = ptr->next) {
      push_back(ptr->datum);
  }
}

template<typename T>
List<T>::List(){
  first = nullptr;
  last = nullptr;
  length = 0;
}

template<typename T>
List<T>::~List(){
  clear();
}

template<typename T>
List<T>::List(const List& other){
  length = 0;
  first = last = nullptr;
  copy_all(other);
}

template<typename T>
List<T> & List<T>::operator=(const List<T>& rhs){
  if (this == &rhs) { return *this; }
  clear();
  copy_all(rhs);
  return *this;
}

//REQUIRES: i is a valid, dereferenceable iterator associated with this list
//MODIFIES: may invalidate other list iterators
//EFFECTS: Removes a single element from the list container
template<typename T>
void List<T>::erase(Iterator i) {
  if (length == 1) {
    pop_front();
  }
  /*
  else if (length == 2) {
    if (i.node_ptr == first) {
      pop_front();
    }
    else if (i.node_ptr == last) {
      pop_back();
    }
  }
  */
  else if (i.node_ptr == first) {
      pop_front();
    }
  else if (i.node_ptr == last) {
      pop_back();
    }
  else {
    Node *n = i.node_ptr;
    (n->prev)->next = n->next;
    (n->next)->prev = n->prev;
    delete n;
    length--;
  }
}

//REQUIRES: i is a valid iterator associated with this list
//EFFECTS: inserts datum before the element at the specified position.
template<typename T>
void List<T>::insert(Iterator i, const T &datum) {
  if (i.node_ptr == first) {
    push_front(datum);
  }
  else if (i.node_ptr == nullptr) {
    push_back(datum);
  }
  else {
    Node *p = new Node;
    (i.node_ptr->prev)->next = p;
    p->datum = datum;
    p->prev = i.node_ptr->prev;
    p->next = i.node_ptr;
    (i.node_ptr->prev) = p;
    i.node_ptr = p;
    length++;
  }
}






#endif // Do not remove this. Write all your code above this line.
