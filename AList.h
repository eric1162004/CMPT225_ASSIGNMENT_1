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
    theCapacity = 10;
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

  // increase the capacity of the list
  void _expandCapacity()
  {
    // Check if the list have more than 1 space left.
    // If so, no expansion is needed.
    if (theCapacity - 1 > theSize)
      return;

    // Allocate space for new array
    Object *temp = new Object[theCapacity * 2];

    // Case when the array is not wrapped around
    if (left < right)
    {
      for (int i = left + 1; i < right; i++)
        temp[i] = objects[i];
    }
    // Case when the array is wrapped around, 
    // i.e. left comes after the right.
    else
    {
      // Copy items over from left to the end of the old array
      for (int i = left + 1; i < theCapacity; i++)
        temp[i + theCapacity] = objects[i];
        
      // Copy items over from the begining of the old array to right
      for (int i = 0; i < right; i++)
        temp[i] = objects[i];
    }

    // delete current objects
    delete objects;

    // set temp to objects
    objects = temp;

    // update theCapacity
    left = left + theCapacity;
    theCapacity *= 2;
  }

  void addLeft(const Object x) // Insert a new object at the left end
  {
    // Implement this....
    _expandCapacity();
    theSize++;
    objects[left] = x;
    // add theCapacity as an offset to ensure left - 1 is positive
    left = (left + theCapacity - 1) % theCapacity;
  }

  void addRight(const Object x) // Insert a new object at the right end
  {
    _expandCapacity();
    theSize++;
    objects[right] = x;
    right = (right + 1) % theCapacity;
  }

  Object removeRight() // Remove and return the object at the right end
  {
    // Implement this
    // If size is zero, throw error
    if (theSize == 0)
      throw 1;

    theSize--;
    // There is a possibility that right - 1 is negative,
    // which make the modulus result incorrect
    // Therefore we must ensure right is a positive number
    // by adding theCapacity as a offset.
    right = right - 1 < 0 ? (right - 1 + theCapacity) % theCapacity : (right - 1);
    return objects[right];
  }

  Object removeLeft() // Remove and return the object at the left end
  {
    // Implement this
    // If size is zero, throw error
    if (theSize == 0)
      throw 1;

    theSize--;
    left = (left + 1) % theCapacity;
    return objects[left];
  }

  void display() const // print out the contents of the AList
  {
    // Implement this.
    int current = (left + 1) % theCapacity;
    int count = theSize;
    while (count > 0)
    {
      cout << objects[current] << ' ';
      current = (current + 1) % theCapacity;
      count--;
    }
    cout << endl;
  }

  void ddisplay() const // print out the contents of the objects
  // array, and relevant variables, for debugging or verifying
  // correctness.
  {
    // Implement this.
    cout << "============================" << endl;
    cout << "theSize: " << theSize << endl;
    cout << "theCapacity: " << theCapacity << endl;
    cout << "left: " << left << endl;
    cout << "right: " << right << endl;

    cout << "display objects:" << endl;
    display();
    cout << "============================" << endl;
  }

private:
  int theSize;
  int left;
  int right;
  int theCapacity;
  Object *objects;
};

#endif
