// File Name: IntStack.cpp
// Author: Ricardo Reyna
// Date: 12/06/2017
// Assignment 6
// CS 2308.256 Fall 2017
// Instructor: Yijuan Lu
//
//

#include "IntStack.h"
#include <iostream>
#include <cassert>


using namespace std;

//constructor
IntStack::IntStack()
{
    head = NULL;
}
//deconstructor
IntStack::~IntStack()
{

    while(head != NULL)
    {
        Node *ptr = new Node;
        ptr = head;
        head = head -> next;
        delete ptr;
    }
}

//***********************************************************
// isEmpty(): Check if stack is empty
//***********************************************************
bool IntStack::isEmpty()
{
return(head==NULL);
}
//***********************************************************
// isFull(): Check if stack is full
//***********************************************************
bool IntStack::isFull()
{
    return false;
}

//***********************************************************
// push(int num): Stores data into the stack
//
// param 1: data that is been stored into the stack
//***********************************************************
void IntStack::push(int num)
{
    if(isFull())
    {
        cout << "Stack is Full" << endl << endl;
        assert(!isFull());
    }

    else
    {
        Node *newNode = new Node;
        newNode -> next = head;
        head = newNode;
        newNode -> data = num;
    }
}

//***********************************************************
// pop(): Removes data from the stack and then returns it
//***********************************************************
int IntStack::pop()
{
    assert(!isEmpty());

    int result;
    Node *ptr;

    ptr = head;
    head = head -> next;
    result = ptr -> data;

    delete ptr;

    return result;
}
