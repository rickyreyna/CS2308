// File Name: IntStack.h
// Author: Ricardo Reyna
// Date: 12/06/2017
// Assignment 6
// CS 2308.256 Fall 2017
// Instructor: Yijuan Lu
//
// File was given by professor

#ifndef INTSTACK_H
#define INTSTACK_H
#include <string>

// Specification file for the IntStack class
// Adapted from Gaddis source code

class IntStack
{
private:
    struct Node{
         int data;
         Node* next;
    };
    Node* head; //ptr to top

public:
    // Constructor
    IntStack();

    //Destructor
    ~IntStack();

    // Stack operations
    void push(int);
    int pop();
    bool isFull();
    bool isEmpty();
};

#endif // INTSTACK_H
