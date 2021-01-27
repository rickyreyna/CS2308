// File Name: assign3_rjr110.cpp
//
// Author: Ricardo Reyna
// Date: 10/13/2017
// Assignment Number: 3
// CS 2308.256 Fall 2017
// Instructor: Yijuan Lu
//

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

bool isSorted(int* , int SIZE);
double chain(int totalInches, int &feet, int &inches);
int grow(int* , int SIZE);
int *subArray(int *array, int index, int length);
int *duplicateArray(int *arr, int SIZE);




int main()
{
    int SIZE = 8;
    int testdata1[SIZE] = {1,2,3,4,5,6,7,8};
    int testdata2[SIZE] = {8,7,6,5,4,3,2,1};
    int testdata3[SIZE] = {1,2,3,5,4,6,7,8};
    string testdata_array1 = "1 2 3 4 5 6 7 8";
    string testdata_array2 = "8 7 6 5 4 3 2 1";
    string testdata_array3 = "1 2 3 5 4 6 7 8";
    string grow_result = "1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9";
    string subArray_result = "6 7 8 9";
    int start = 5;
    int length = 4;
    int *ptr_array1 = testdata1;
    int *ptr_array2 = testdata2;
    int *ptr_array3 = testdata3;
    int feet = 0;
    int inches = 0;
    int totalInches = 53;
    double chain_result = 0;
    bool result = false;
    int *ptr_grow;

    result = isSorted(testdata1, SIZE);
    cout << result << endl;
    result = isSorted(testdata2, SIZE);
    cout << result << endl;
    result = isSorted(testdata3, SIZE);
    cout << result << endl;
    chain_result = chain(totalInches, feet, inches);
    cout << chain_result << " " << feet << " " << inches << " " << endl;

    *ptr_grow = grow(testdata1, SIZE);

    for(int i = 0; i < (SIZE*2); i++)
    {
        cout << ptr_grow[i]<< endl;
    }


    return 0;
}


bool isSorted (int *ptr_array1, int SIZE)
{
    for(int i = 0; i < SIZE; i++)
    {
        if (ptr_array1[i] > ptr_array1[i+1])
            return false;
    }

return true;
}

double chain (int totalInches, int &feet, int &inches)
{
    feet = totalInches / 12;
    inches = totalInches % 12;

return (feet * 3.49) + (inches * (.30));
}


int grow (int *ptr_array1, int SIZE)
 {
    int *new_array;
    new_array = new int[SIZE*2];

        for(int i = 0; i < SIZE; i++)
        {
            new_array[i] = ptr_array1[i];
            new_array[i+1] = ptr_array1[i];
        }


return *new_array;
 }


int *subArray(int *ptr_array1, int start, int length)
{
    int *result = duplcateArray( , );

return result;
}



int *duplicateArray(int *arr, int SIZE)
{
    int *newArray;
    if(SIZE <= 0)
    {
        return NULL;
    }

    newArray = new int [SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        newArray[i] = arr[i];
    }

return newArray;
}





