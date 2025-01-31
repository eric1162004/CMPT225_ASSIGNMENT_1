/*
Full name:    Eric Cheung
Student ID:   301125805
Computing-id: hccheung

Copyright Notice:
This code is part of the assignment 1b for CSPT 225, Spring 2025.
Unauthorized copying or distribution is prohibited.

Purpose of this file:
This program verifies the AList class's removeLeft() behavior
when trying to remove an element from an empty list.
*/
#include "AList.h"

int main(int argc, char const *argv[])
{
    AList<int> list; // Create an empty list

    // Capacity overflow should trigger assertion alert.
    list.removeLeft();
    
    return 0;
}
