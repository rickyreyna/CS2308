#ifndef QUESTION_H
#define QUESTION_H
#include <iostream>
#include <string>

using namespace std;


class Question
{

private:
    string set_Stem;
    string answers[4];
    char key;

 public:
 	Question();
 	Question(string, string*, char);
    void setStem(string);
    void setAnswers(string*, int);
    void setKey(char);
    string getStem();
    string getAnswer(int);
    char getKey();
    void display(int);
};

#endif
