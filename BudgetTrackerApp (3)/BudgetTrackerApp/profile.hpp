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

#include "account.hpp"
#include "commandhistory.hpp"
#include "commands.hpp"
#include "dashboard.hpp"
#include "data.hpp"
#include "randomization.hpp"

using namespace std;
string profile(string pfp, bool match, map<string, float> &acc)
{
    // Set wallet and hasQuit data
    double wallet = 500;
    bool hasQuit = true;
    if (match)
    {
        loadData(pfp, wallet, acc);
    }
    // Introduce the profile and show the instructions
    cout << "" << endl;
    cout << "" << endl;
    cout << "Welcome " << (match ? "back " : "") << pfp << endl;
    commands("i", wallet, accounts);
    //
    do
    {
        string prompt;

        cout << "> For any assistance, type g or guide for instructions" << endl;
        cout << endl;
        cout << "Type text " << pfp << ">: ";
        getline(cin, prompt);
        commands(prompt, wallet, accounts, pfp);

        if (prompt == "quit" || prompt == "exit")
            hasQuit = false;

    } while (hasQuit);
    // Ending
    cout << "You have exited the program, thank you for this pleasent experience " << pfp << endl;
    return pfp;
}