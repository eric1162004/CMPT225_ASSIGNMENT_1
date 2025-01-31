/*
Full name:    Eric Cheung
Student ID:   301125805
Computing-id: hccheung

Copyright Notice:
This code is part of the assignment 1b for CSPT 225, Spring 2025.
Unauthorized copying or distribution is prohibited.

Purpose of this file:
This program verifies the AList class's addRight() behavior
when trying to add an element to a full list.
*/
#include "AList.h"

int main(int argc, char const *argv[])
{
    const int CAPACITY = 12;

    AList<int> list; // Create a full list with size of 12
    for (size_t i = 0; i < CAPACITY; i++)
        list.addRight(i);

    // Capacity overflow should trigger assertion alert.
    list.addRight(CAPACITY + 1);
    
    return 0;
}
