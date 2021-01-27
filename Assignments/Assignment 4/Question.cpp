#include "Question.h"
#include <iostream>
#include <string>

using namespace std;


	Question::Question(){

	}

//***********************************************************
// Question Question: Class Structure made to save data
//
// param-1 Saves the question
// param-2 Saves the answers
// param-3 Saves the answer key
//
//***********************************************************
	Question::Question(string q, string a[], char k)
	{
		setStem(q);
		setAnswers(a, 4);
        setKey(k);
	}

//***********************************************************
// void setStem: saves the question in a string variable
//
// param-1 variable that is being used to pull the data from main funciton
//
//***********************************************************
    void Question::setStem(string x)
    {
        set_Stem = x;
    }

//***********************************************************
// void setAnswers: saves the answers into a variable
//
// param-1 array variable that holds all the answers
// param-2 size of the variable
//
//***********************************************************
     void Question::setAnswers(string a[], int SIZE)
    {
        for(int i=0; i < SIZE; i++)
        {
        answers[i] = a[i];
        }
    }

//***********************************************************
// void setKey: saves the answer key into a variable
//
// param-1 variable used to pass the key answer data
//
//***********************************************************
     void Question::setKey(char k)
    {
        key = k;
    }

//***********************************************************
// string getStem once the question has been passed to the class variable this
// function is able to return it
//
// returns: the string variable
//***********************************************************
    string Question::getStem()
    {
        return set_Stem;
    }

//***********************************************************
// string getAnswer once all the answers have been passed to the class
// variable this function is able to return the desire answer
//
// param-1 position in the array where one want to get the answer
// returns: the answer the person desires
//***********************************************************
    string Question::getAnswer(int p)
    {
        return answers[p];
    }

//***********************************************************
// string getKey once all the answers have been passed to the class
// variable this function is able to return the key answer
//
// returns: the key answer
//***********************************************************
    char Question::getKey()
    {
        return key;
    }

//***********************************************************
// void display once all the answers have been passed to the class
// variable this function is able to return the desire answer
//
// param-1 number of question that one wants to be display
// prints to the console the question and answer that the person desires to
//***********************************************************
    void Question::display(int n)
    {
    	cout << n << ". " << getStem() << endl;

    	for(int i=0; i<4; i++)
        {
    		cout << (char)('A'+i) << ". " << answers[i] << endl;
		}

		cout << endl;
	}




