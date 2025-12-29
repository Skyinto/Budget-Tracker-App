#include <iostream>
#include <string>
#include <map>
#include <regex>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <random>
#include <fstream>
#include <stdio.h>
using namespace std;

#include "account.hpp"
#include "commandhistory.hpp"
#include "commands.hpp"
#include "dashboard.hpp"
#include "data.hpp"
#include "profile.hpp"

// Randomize prompt function
void typeRandom(double &wallet)
{
    string range;

    while (true)
    {
        cout << "Type in wallet number range under 1001 and above 0 (leave/back/quit to quit): ";
        cin >> range;
        bool numVis = false;
        // Need array loop according to the project description. Given strings are basically arrays, it works doesn't it?
        if (range == "quit" || range == "leave" || range == "back")
        {
            break;
        }
        // Check input validation
        for (char c : range)
        {

            if (!isdigit(c))
            {
                cout << "" << endl;
                cout << "" << endl;
                cout << "The value must only contain numbers";
                cout << "" << endl;
                cout << "" << endl;
                cout << "" << endl;
                numVis = true;
                break;
            }
        }

        if (numVis)
        {
            random(wallet, true);
        }
        else if (stod(range) > 0 && stod(range) <= 1000)
        {
            random(wallet, false, stod(range));
        }
        else
        {
            random(wallet, true);
        };
        commandTimes();
    };
    cout << "" << endl;
    cout << "You have left the randomization program" << endl;
    cout << "" << endl;
    return;
}

// Randomize the money amount to add onto wallet
void random(double &wallet, bool err, int rangenums)
{
    // If the input validation is invalid, the range will be set to 100 by default
    // Randomize from 1 - 1000
    srand(time(0));
    int rng = rand() % (rangenums) + 1;
    wallet += rng;
    cout << "" << endl;
    cout << "-----------------------" << endl;
    if (err)
    {
        cout << "Since your input is incorrect, your given a range of 100 by default" << endl;
        cout << "" << endl;
    }
    cout << "+ $" << rng << endl;
    cout << "Your wallet now has: $ " << wallet << endl;
    cout << "-----------------------" << endl;
    cout << "" << endl;
    return;
}

void random(double &wallet, bool err, int rangenums)
{
    // If the input validation is invalid, the range will be set to 100 by default
    // Randomize from 1 - 1000
    srand(time(0));
    int rng = rand() % (rangenums) + 1;
    wallet += rng;
    cout << "" << endl;
    cout << "-----------------------" << endl;
    if (err)
    {
        cout << "Since your input is incorrect, your given a range of 100 by default" << endl;
        cout << "" << endl;
    }
    cout << "+ $" << rng << endl;
    cout << "Your wallet now has: $ " << wallet << endl;
    cout << "-----------------------" << endl;
    cout << "" << endl;
    return;
}