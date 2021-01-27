// File Name: driver.cpp
// Author: Ricardo Reyna
// Date: 12/06/2017
// Assignment 6
// CS 2308.256 Fall 2017
// Instructor: Yijuan Lu
//
// Program ask user to type the infile name
// Brackets are stored into variable and then it's been check if they match

#include <iostream>
#include <fstream>
#include <string>
#include "IntStack.h"
#include "IntStack.cpp"

using namespace std;

int main()
{
    string in_file; //User inputs the name of the file into this variable
    char data; // variable used to store the infile data
    char temp[10000]; // array used to store only brackets characters
    int index = 0; // amount of characters brackets (used to keep track of them)
    IntStack Stack; // stack used to store the brackets

    ifstream fin;

    // Ask users to type input file name until it works.
    do
    {
    cout << "Please enter the file name you want to open: " << endl;
    cin >> in_file;
    fin.open(in_file.c_str());
    if(!fin)
    {
        cout << "Error opening the file. Please try again." << endl;
    }
    } while(!fin);

    // Stores only certain brackets to the array
    while( fin >> data  )
    {
        if( data == '(' || data == ')' || data == '[' || data == ']'  || data == '{' || data == '}' )
            {
                temp[index] = data;
                index++;
            }
    }

   // If there are odd number of brackets, then they are not paired properly so it returns false
   cout << "amount of brackets: " <<  index << endl;

   if( (index %2) == 1)
        {
            cout << "ERROR. Brackets do not match. (There are missing brackets)" << endl;
            return false;
        }


    // Loop that goes through the array that has the special brackets
    for(int i = 0; i <= index; i++)
    {
        // If the brackets are opening it push them to the stack
        if( temp[i] == '(' || temp[i] == '[' || temp[i] == '{' )
            {
                Stack.push(temp[i]);
            }

        // If the  brackets are closing then it will check if it pairs with the last opening bracket
        else if( temp[i] == ')' || temp[i] == ']' || temp[i] == '}' )
        {
            Stack.push(temp[i]);

            char check_op;
            char check_cl;

            check_cl = Stack.pop();

            // If the stack is not empty then pop
            if((Stack.isEmpty()) == false)
            {
                check_op = Stack.pop();
            }

            // Checks for pair of brackets
            if( (check_op == '(' && check_cl == ')') || (check_op == '[' && check_cl == ']') || (check_op == '{' && check_cl == '}') )
            {
                 cout << "There is a pair of matching brackets" << endl;
            }


            else
            {
               cout << "ERROR. Brackets do not match." << endl;
                return false;
            }

        }

    }

    cout << "All brackets are matching!" << endl;
    return 0;
}
