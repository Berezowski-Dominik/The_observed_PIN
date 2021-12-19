// The_observed_PIN.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*Alright, detective, one of our colleagues successfully observed our target person, Robby the robber. 
We followed him to a secret warehouse, where we assume to find all the stolen stuff. The door to this 
warehouse is secured by an electronic combination lock. Unfortunately our spy isn't sure about the PIN he saw,
when Robby entered it.

The keypad has the following layout:

┌───┬───┬───┐
│ 1 │ 2 │ 3 │
├───┼───┼───┤
│ 4 │ 5 │ 6 │
├───┼───┼───┤
│ 7 │ 8 │ 9 │
└───┼───┼───┘
    │ 0 │
    └───┘
He noted the PIN 1357, but he also said, it is possible that each of the digits he saw could 
actually be another adjacent digit (horizontally or vertically, but not diagonally). E.g. instead 
of the 1 it could also be the 2 or 4. And instead of the 5 it could also be the 2, 4, 6 or 8.

He also mentioned, he knows this kind of locks. You can enter an unlimited amount of wrong PINs, 
they never finally lock the system or sound the alarm. That's why we can try out all possible (*) variations.

* possible in sense of: the observed PIN itself and all variations considering the adjacent digits

Can you help us to find all those variations? It would be nice to have a function, that returns an array (or a list in Java and C#) of all variations for an observed PIN with a length of 1 to 8 digits. We could name the function getPINs (get_pins in python, GetPINs in C#). But please note that all PINs, the observed one and also the results, must be strings, because of potentially leading '0's. We already prepared some test cases for you.*/
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> get_pins(string observed) 
{
    //  vector with number and their neighbors 
    vector <vector <char>> NeighborsAndNumber = { {'0','8'},{'1','2','4'},{'1','2','3','5'},{'2','3','6'},
    {'1','4','5','7'},{'2','4','5','6','8'},{'3','5','6','9'},{'4','7','8'},{'0','5','7','8','9'},{'6','8','9'} };

    //  search witch number in input string have most neighbors and how many number of strings return    
    int numberOfStrings = 1;
    
    for (int i = 0; i < observed.length(); i++)
    {
        numberOfStrings *= NeighborsAndNumber[observed[i] - '0'].size();
    }

    //  create a ReturnStrings, or inicialization return strings

    vector <string> ReturnStrings(numberOfStrings);

    int MultiplicationSizeValue = 1;

    for (int i = 0; i < observed.length(); i++)
    {
        MultiplicationSizeValue *= NeighborsAndNumber[observed[i] - '0'].size();

        for (int j = 0, k = 0; j < numberOfStrings; j++)
        {
            //  example input 012 output 011,012,013,015,021,022,023,025,041,042,043,045
            //  811,812,813,815,821,822,823,825,841,842,843,845

            if (j != 0 && j % (numberOfStrings / MultiplicationSizeValue) == 0)    k++;
            if (k == NeighborsAndNumber[observed[i] - '0'].size()) k = 0;

            ReturnStrings[j] += NeighborsAndNumber[observed[i] - '0'][k];
        }
    }
    
    return ReturnStrings;
}

int main()
{
    get_pins("012");

}

