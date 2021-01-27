// File Name: assign1_rjr110.cpp
//
// Author: Ricardo Reyna
// Date: 09/18/2017
// Assignment Number: 1
// CS 2308.256 Fall 2017
// Instructor: Yijuan Lu
//
// Initializes a data type called  Rat with three elements that stores name,
// weight, and maze_time. Then initialize an array of rats with the data type
// Rat. After that a function gets the average weight of the rats and another
// function shows the slowest and fast rats.
//
// Outputs the information of the rats, the average weight of the rats, the
// fastest rat, and the slowest rat.

#include <iostream>
#include <iomanip>
using namespace std;

    struct Rat
    {
        string name;
        double weight;
        double maze_time;

    };

void Avg_Weight(Rat *rats);
void Fastest_and_slowest_time(Rat *rats);


int main()
{

    double avg_weight   = 0;


    Rat rats[9] = {
                    {"Ben" , 6.5 , 29},
                    {"Fred" , 5.8 , 31},
                    {"Splinter" , 7.7 , 33},
                    {"Lima Bean" , 6.5 , 27},
                    {"Black Bean" , 5.8 , 31},
                    {"Pinto Bean" , 7.7 , 33},
                    {"Skat" , 6.5 , 29},
                    {"Big Pook" , 9.8 , 34},
                    {"Tiger" , 7.7 , 33}
                  };

    for(int i = 0; i < 9; i++)
    {
        cout << rats[i].name << ", " << rats[i].weight << ", " <<
                rats[i].maze_time << endl;

    }

    cout << endl;

Avg_Weight(rats);
Fastest_and_slowest_time(rats);

    return 0;

}


//******************************************************************************
// Avg_Weight: Determines the average weight of the rats
//
// Rat *rats: Array Structure of the rats
//
//******************************************************************************

void Avg_Weight(Rat *rats)
{
    double avg_weight;

    for(int w = 0; w < 9; w++)
    {
        avg_weight += rats[w].weight;
    }
cout << "The average weight of the rats is "
     << fixed << setprecision(1)
     << (avg_weight/9) << " oz." << endl;

}

//******************************************************************************
// Fastest_and_slowest_time: Determines the fastest and slowest rats
//
// Rat *rats: Array Structure of the rats
//
//******************************************************************************
void Fastest_and_slowest_time(Rat *rats)
{
    int fastest_time  = 0;
    int slowest_time = 9999999;
    string fst_rat_name;
    string slw_rat_name;

        for(int f = 0; f < 9; f++)
    {
        if(fastest_time < rats[f].maze_time)
        {
            fastest_time = rats[f].maze_time;
            fst_rat_name = rats[f].name;
        }
        if(slowest_time > rats[f].maze_time)
        {
            slowest_time = rats[f].maze_time;
            slw_rat_name = rats[f].name;
        }
    }

    cout << "The fastest rat is " << fst_rat_name << " which took a time of: "
         << fastest_time << "." << endl << "The slowest rat is " << slw_rat_name
         << " which took a time of: " << slowest_time << "." << endl;
}

