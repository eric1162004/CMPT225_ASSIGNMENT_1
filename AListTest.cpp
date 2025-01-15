#include "AList.h"

const int ITEMCOUNT = 15;

// Display function test result (PASS or FAIL)
// along with a message
void printTestResults(int condition, string message)
{
    cout << (condition ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m")
         << ": " << message << endl;
}

// Check adding items to the right end of the list
void addRightTest()
{
    AList<int> myList;

    for (int i = 1; i <= ITEMCOUNT; i++)
    {
        myList.addRight(i);
        printTestResults(myList.size() == i,
                         "addRight() should add one element at a time");
    }
}

// Check adding item the left end of the list
void addLeftTest()
{
    AList<int> myList;

    for (int i = 1; i <= ITEMCOUNT; i++)
    {
        myList.addLeft(i);
        printTestResults(myList.size() == i,
                         "addLeft() should add one element at a time");
    }
}

// Check if empty() returns the empty state or not.
void emptyTest()
{
    AList<int> myList;
    printTestResults(myList.empty() == 1,
                     "empty() should return 1 when the list is empty.");

    myList.addRight(1);
    printTestResults(myList.empty() == 0,
                     "empty() should return 0 when the list is not empty.");
}

// Verify removeRight() functionailies
void removeRightTest()
{
    AList<int> myList;

    // Add elements to the list
    for (int i = 1; i <= ITEMCOUNT; i++)
        myList.addRight(i);

    // Remove elements and store the removed values
    int temp;
    for (int i = 1; i <= ITEMCOUNT; i++)
        temp = myList.removeRight();

    printTestResults(myList.size() == 0,
                     "removeRight() should remove 1 item from the right");
    printTestResults(temp == 1,
                     "removeRight() should return the removed item");

    // Expect exception when removing from an empty list
    try
    {
        myList.removeRight();
    }
    catch (int error)
    {
        printTestResults(error,
                         "removeRight() should throw an error "
                         "if attempting to remove from a empty list");
    }
}

// Verify removeLeft() functionailies
void removeLeftTest()
{
    AList<int> myList;

    // Add elements to the list
    for (int i = 1; i <= ITEMCOUNT; i++)
        myList.addLeft(i);

    int temp;
    for (int i = ITEMCOUNT; i > 0; i--)
    {
        // Remove elements and check size
        temp = myList.removeRight();
        printTestResults(myList.size() == i - 1,
                         "removeLeft should decrease size by 1.");
        // Check removed values
        printTestResults(temp == ITEMCOUNT + 1 - i,
                         "removeLeft() should return the removed item.");
    }

    // Expect exception when removing from an empty list
    try
    {
        myList.removeLeft();
    }
    catch (int error)
    {
        printTestResults(error, "removeLeft() should throw"
                                " an exception on empty list removal.");
    }
}

// Checks if size() returns the
// correct number of elements in the list
void sizeTest()
{
    AList<int> myList;

    // Test initial size
    printTestResults(myList.size() == 0,
                     "size() should return 0 for an empty list");

    // Add elements and check size
    for (int i = 1; i <= ITEMCOUNT; i++)
    {
        myList.addRight(i);
        printTestResults(myList.size() == i,
                         "size() should return correct"
                         " size after adding elements");
    }

    // Remove elements and check size
    for (int i = ITEMCOUNT; i > 0; i--)
    {
        myList.removeRight();
        printTestResults(myList.size() == i - 1,
                         "size() should return correct"
                         " size after removing elements");
    }
}

// Checks if clear() removes all elements from the list
void clearTest()
{
    AList<int> myList;

    // Add some elements to the list
    for (int i = 1; i <= ITEMCOUNT; i++)
    {
        myList.addRight(i);
    }
    myList.clear();

    // Check size after clear()
    printTestResults(myList.size() == 0,
                     "clear() should 0 the size of the list.");

    // Check if list is empty
    printTestResults(myList.empty(),
                     "empty() should return true after clear()");

    // Expect exception when removing from an empty list
    try
    {
        myList.removeRight();
    }
    catch (int error)
    {
        printTestResults(error,
                         "Should throw an exception if try "
                         "to remove a item after clear()");
    }

    // Try to add an element after clear()
    myList.addRight(1);
    printTestResults(myList.size() == 1,
                     "List should have 1 element"
                     " after adding to an cleared list");
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
