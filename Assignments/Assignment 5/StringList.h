#ifndef STRINGLIST_H
#define STRINGLIST_H

// File Name: StringList.h
//
// Author: Yijuan Lu
// Date: 11/06/2017
// Assignment Number: 5
// CS 2308 Fall 2017
// Instructor: Yijuan Lu
//
// Represents a list of strings.
// Supports adding and removing strings, displaying and sorting strings,
// finding the minimum and count of the number of strings in the list.

#include <string>
using namespace std;

class StringList
{
  private:
    struct StringNode          // the Nodes of the linked list
    {
        string data;           // data is a string
        StringNode *next;      // points to next node in list
    };

    StringNode *head;           // the head pointer

  public:
    StringList();
    ~StringList();

    int count();
    void add(string);
    bool remove(string);
    void display();
    string minimum();
    void sort();
};

#endif // STRINGLIST_H
