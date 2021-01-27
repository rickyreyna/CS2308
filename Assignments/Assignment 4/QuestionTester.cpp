// File Name: QuestionTester.cpp
//
// Author: Yijuan Lu
// Date: 10/30/2017
// Assignment Number:4
// CS 2308 Fall 2017
// Instructor: Yijuan Lu
//
// Driver to test the Question class.
// Initialize multiple objects from a class. Then
// through hard coded code we input the data into the class. Later, the program
// outputs all the data to the screen in an organized manner.

#include <iomanip>
#include "Question.h"
#include "Question.cpp"

using namespace std;

int main()
{
    int SIZE = 4; // Size variable for the answers array

    // The following code was given to us by the professor:
    Question q1;
    q1.setStem("What name is given to half of a Byte (4 bits)?");
    string q1Answers[] = {"Nibble","Ort","Scrap","Snippet"};
    q1.setAnswers(q1Answers, SIZE);
    q1.setKey('A');

    cout<< "q1 stem: " << q1.getStem() << endl;
    cout<< "q1 first answer: " << q1.getAnswer(0) << endl;
    cout<< "q1 last answer: " << q1.getAnswer(3) << endl;
    cout <<"q1 correct answer: " << q1.getKey() << endl;
    cout << endl;
    string q2Answers[] = {"China","India","Mexico","Australia"};
    Question q2("Which country is home to the Kangaroo?",q2Answers,'D');

    q1.display(2);
    cout << endl;

    // Here the code given by the professor ends.

    // The following are variables made to hold the answers for each questions
    string q3Answers [] = {"Compass","Protractor","Ruler","T-Square"};
    string q4Answers [] = {"Camel","Eagle","Lion","Alligator"};
    string q5Answers [] = {"Birdie","Puck","Dart","Tile"};

    q1.display(1); // Displays question 1 with answers
    q2.display(2);  // Displays question 2 with answers
    Question q3("What do you use to measure an angle?", q3Answers, 'B');
    q3.display(3);  // Displays question 3 with answers
    Question q4("The Great Sphinx has the head of a human and the body of a what?", q4Answers, 'C');
    q4.display(4);  // Displays question 4 with answers
    Question q5("What is the flat rubber disc used in a game of ice hockey?", q5Answers, 'B');
    q5.display(5);  // Displays question 5 with answers

    cout << "Answers: " << endl << q1.getKey() << " " << q2.getKey() << " "
         << q3.getKey() << " " << q4.getKey() << " " << q5.getKey() << endl;


}
/* Expected output:

 q1 stem: What name is given to half of a Byte (4 bits)?
 q1 first answer: Nibble
 q1 last answer: Snippet
 q1 correct answer: A

 Which country is home to the Kangaroo?
 A. China
 B. India
 C. Mexico
 D. Australia

 */
