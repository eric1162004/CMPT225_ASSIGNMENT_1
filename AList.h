/*
Full name:    Eric Cheung
Student ID:   301125805
Computing-id: hccheung
Lab Section:  CMPT 125 D102
*/
#ifndef ALIST_H
#define ALIST_H

#include <iostream>
using namespace std;

template <typename Object>
class AList
{
public:
  AList()
  {
    theCapacity = 12;
    objects = new Object[theCapacity];
    theSize = 0;
    left = 0;  // array index of location just before the left-most list element
    right = 1; // array index just past the right-most list element
  }

  ~AList()
  {
    delete[] objects;
  }

  bool empty() const { return size() == 0; }
  int size() const { return theSize; }
  void clear()
  {
    // remove all list contents
    //
    // Implement this...
    left = 0;
    right = 1;
    theSize = 0;
  }

  // Operations

  // Assumption for addLeft and addRight:
  // The user is aware that adding an item
  // to a full list will lead to errors.
  // In this implementation, we simply overwrite existing values.

  void addLeft(const Object x) // Insert a new object at the left end
  {
    // Implement this....
    ++theSize;
    objects[left] = x;
    left = (left - 1 + theCapacity) % theCapacity;
  }

  void addRight(const Object x) // Insert a new object at the right end
  {
    ++theSize;
    objects[right] = x;
    right = (right + 1) % theCapacity;
  }

  // Assumption for removeRight and removeLeft:
  // The user is aware that removing an item
  // from a empty list will lead to errors.
  // In this implementation, we handle it returning the value at
  // (right - 1 + theCapacity) % theCapacity for removeRight, and
  // (left+ 1) % theCapacity for  removeLeft.

  Object removeRight() // Remove and return the object at the right end
  {
    // Implement this
    // To ensure we do not mod a negative value,
    // we add theCapacity to right - -1 as a offset.
    --theSize;
    right = (right - 1 + theCapacity) % theCapacity;
    return objects[right];
  }

  Object removeLeft() // Remove and return the object at the left end
  {
    // Implement this
    --theSize;
    left = (left + 1) % theCapacity;
    return objects[left];
  }

  void display() const // print out the contents of the AList
  {
    // Implement this.
    cout << "The contents of Alist:\n"
         << "theSize: " << theSize << "\n"
         << "left: " << left << "\n"
         << "right: " << right << "\n"
         << "theCapacity: " << theCapacity << "\n";
  }

  void ddisplay() const // print out the contents of the objects
  // array, and relevant variables, for debugging or verifying
  // correctness.
  {
    // Implement this.
    cout << "The contents of the objects array: <";
    for (int i = 0; i < theCapacity; i++)
    {
      cout << objects[i]
           << ((i == theCapacity - 1) ? ">\n" : ", ");
    }
  }

private:
  int theSize;
  int left;
  int right;
  int theCapacity;
  Object *objects;
};

#endif
