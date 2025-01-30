/*
Full name:    Eric Cheung
Student ID:   301125805
Computing-id: hccheung

Copyright Notice:
This code is part of the assignment 1b for CSPT 225, Spring 2025.
Unauthorized copying or distribution is prohibited.

Purpose of this file:
A test program that demonstrates the correctness of 
an implementation of the AList class

It is assumed that the program user is aware 
of the item capacity of Alist and doing so will lead to errors.

Therefore, this test suite does not test the following cases:
1. adding an item to a full Alist
2. removing an item from a empty Alist.
*/
#include "AList.h"

const int ITEMCOUNT = 12; // Set item size to test

// Display function test result (PASS or FAIL)
// along with a message
void printTestResults(int condition, string message)
{
    cout << (condition ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m")
         << ":\t" << message << endl;
}

// addRight(i) should increase AList size by 1
void addRightTest()
{
    AList<int> myList;
    bool isValid = true;

    for (int i = 1; i <= ITEMCOUNT; i++)
    {
        myList.addRight(i);
        isValid = (myList.size() == i);
        if (!isValid)
            break;
    }

    printTestResults(isValid,
                     "addRight(i) should increase AList size by 1;");
}

// addLeft(i) should increase AList size by 1
void addLeftTest()
{
    AList<int> myList;
    bool isValid = true;

    for (int i = 1; i <= ITEMCOUNT; i++)
    {
        myList.addLeft(i);
        isValid = (myList.size() == i);
        if (!isValid)
            break;
    }

    printTestResults(isValid,
                     "addLeft() should add one element at a time");
}

// empty() should return 1 when the list is empty.
// empty() should return 0 when the list is not empty.
void emptyTest()
{
    AList<int> myList;
    printTestResults(myList.empty() == 1,
                     "empty() should return 1 when the list is empty.");

    myList.addRight(1);
    printTestResults(myList.empty() == 0,
                     "empty() should return 0 when the list is not empty.");
}

// removeRight() should decrease AList size by 1.
// removeRight() should return the removed item.
void removeRightTest()
{
    AList<int> myList;
    bool isSizeValid = true;
    bool isItemValid = true;

    // Add elements to the list
    for (int i = 1; i <= ITEMCOUNT; i++)
        myList.addRight(i);

    // Remove elements
    int temp;
    for (int i = 1; i <= ITEMCOUNT; i++)
    {
        temp = myList.removeRight();
        isSizeValid = ((ITEMCOUNT - i) == myList.size());
        isItemValid = ((ITEMCOUNT + 1 - i) == temp);
        if (!isSizeValid || !isItemValid)
            break;
    }

    printTestResults(isSizeValid,
                     "removeRight() should decrease AList size by 1.");
    printTestResults(isItemValid,
                     "removeRight() should return the removed item.\n"
                     "\tremoveRight() should remove item"
                     "from the right end of the list.\n"
                     "\taddRight() should add an item to "
                     "the right end of the line.");
}

// removeLeft() should decrease AList size by 1.
// removeLeft() should return the removed item.
void removeLeftTest()
{
    AList<int> myList;
    bool isSizeValid = true;
    bool isItemValid = true;

    // Add elements to the list
    for (int i = 1; i <= ITEMCOUNT; i++)
        myList.addLeft(i);

    int temp;
    for (int i = ITEMCOUNT; i > 0; i--)
    {
        temp = myList.removeLeft();
        isSizeValid = ((i - 1) == myList.size());
        isItemValid = (i == temp);
        if (!isSizeValid || !isItemValid)
            break;
    }

    // Remove elements and check size
    printTestResults(isSizeValid,
                     "removeLeft() should decrease AList size by 1.");
    // Check removed values
    printTestResults(isItemValid,
                     "removeLeft() should return the removed item.\n"
                     "\tremoveLeft() should remove item "
                     "from the left end of the list.\n"
                     "\taddLeft() should add an item to"
                     "the Left end of the list.");
}

// Testing for size()
void sizeTest()
{
    AList<int> myList;

    // Test initial size
    printTestResults(myList.size() == 0,
                     "size() should return 0 for an empty list");

    // size() should increment after adding elements
    bool isSizeValid = true;
    for (int i = 1; i <= ITEMCOUNT; i++)
    {
        myList.addRight(i);
        isSizeValid = (myList.size() == i);
        if (!isSizeValid)
            break;
    }
    printTestResults(isSizeValid,
                     "size() should increment after adding an element.");

    // size() should decrement after adding elements
    isSizeValid = true;
    for (int i = ITEMCOUNT; i > 0; i--)
    {
        myList.removeRight();
        isSizeValid = (myList.size() == i - 1);
        if (!isSizeValid)
            break;
    }
    printTestResults(isSizeValid,
                     "size() should decrement after removing an element.");
}

// Testing for clear()
void clearTest()
{
    AList<int> myList;

    // Add some elements to the list
    for (int i = 1; i <= ITEMCOUNT; i++)
        myList.addRight(i);
    myList.clear();

    // clear() should zero out the size of the list.
    printTestResults(myList.size() == 0,
                     "clear() should zero out the size of the list.");

    // empty() should return true after calling clear().
    printTestResults(myList.empty(),
                     "empty() should return true after calling clear()");

    // Users should be able to add items after calling clear().
    myList.addRight(1);
    printTestResults(myList.size() == 1,
                     "users should be able to add items after calling clear().");
}

int main()
{
    addRightTest();
    addLeftTest();
    emptyTest();
    removeRightTest();
    removeLeftTest();
    sizeTest();
    clearTest();
    return 0;
}
