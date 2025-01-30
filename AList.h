/*
Full name:    Eric Cheung
Student ID:   301125805
Computing-id: hccheung

Copyright Notice:
This code is part of the assignment 1b for CSPT 225, Spring 2025.
Unauthorized copying or distribution is prohibited.

Purpose of this file:
This file implements the AList class, a circular array-based
list supporting operations including addLeft, addRight, deleteLeft
and deleteRight. The AList class has a fixed maximum capacity of 12.
Behavior is undefined if this limit is exceeded.

Assertions are used for debugging, and test programs
are included to verify functionality.
*/
#ifndef ALIST_H
#define ALIST_H

#include <iostream>
#include <cassert>
using namespace std;

const int CAPACITY = 12;

template <typename Object>
class AList
{
public:
  AList()
  {
    theCapacity = CAPACITY;
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
  bool full() const { return theSize == theCapacity; }
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

  // A helper to verifies if an index is
  // within the bound of the internal array
  bool _isIndexWithArrayBound(int index) const
  {
    return index >= 0 && index < theCapacity;
  }

  void assertOrPrintErrorMsg(bool assertion, string msg)
  {
    if (!assertion)
    {
      std::cerr << msg << std::endl;
      assert(false);
    }
  }

  // Operations

  // Assumption for addLeft and addRight:
  // The user is aware that adding an item
  // to a full list will lead to errors.
  // In this implementation, we simply overwrite existing values.

  void addLeft(const Object x) // Insert a new object at the left end
  {
    // Precondition: the list should not be full.
    assertOrPrintErrorMsg(full() != true,
                "Asserted: Cannot addLeft to a full list.");

    ++theSize;
    objects[left] = x;
    left = (left - 1 + theCapacity) % theCapacity;

    // Postcondition: left should be within the array bound
    assertOrPrintErrorMsg(_isIndexWithArrayBound(left),
                "Asserted: The left index is out of bound.");
  }

  void addRight(const Object x) // Insert a new object at the right end
  {
    // Precondition: the list should not be full.
    assertOrPrintErrorMsg(full() != true,
                "Asserted: Cannot addRight to a full list.");

    ++theSize;
    objects[right] = x;
    right = (right + 1) % theCapacity;

    // Postcondition: right should be within the array bound
    assertOrPrintErrorMsg(_isIndexWithArrayBound(right),
                "Asserted: The right index is out of bound.");
  }

  // Assumption for removeRight and removeLeft:
  // The user is aware that removing an item
  // from a empty list will lead to errors.
  // In this implementation, we handle it returning the value at
  // (right - 1 + theCapacity) % theCapacity for removeRight, and
  // (left+ 1) % theCapacity for  removeLeft.

  Object removeLeft() // Remove and return the object at the left end
  {
    // Precondition: the list should not be empty.
    assertOrPrintErrorMsg(empty() != true,
                "Asserted: Cannot removeLeft from a empty list.");

    --theSize;
    left = (left + 1) % theCapacity;

    // Postcondition: left should be within the array bound
    assertOrPrintErrorMsg(_isIndexWithArrayBound(left),
                "Asserted: The left index is out of bound.");

    return objects[left];
  }

  Object removeRight() // Remove and return the object at the right end
  {
    // Precondition: the list should not be empty.
    assertOrPrintErrorMsg(empty() != true,
                "Asserted: Cannot removeRight from a empty list.");

    // To ensure we do not mod a negative value,
    // we add theCapacity to right - -1 as a offset.
    --theSize;
    right = (right - 1 + theCapacity) % theCapacity;

    // Postcondition: right should be within the array bound
    assertOrPrintErrorMsg(_isIndexWithArrayBound(right),
                "Asserted: The right index is out of bound.");

    return objects[right];
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
