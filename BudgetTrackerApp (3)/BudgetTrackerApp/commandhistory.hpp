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
#include "commands.hpp"
#include "dashboard.hpp"
#include "data.hpp"
#include "profile.hpp"
#include "randomization.hpp"
using namespace std;
int commandTimes()
{

    // Just to add Enums as I don't know where else to add them
    enum Counts
    {
        TIMES = 0
    };
    enum Counts t = TIMES;
    static int timeNums = t;
    timeNums++;
    return timeNums;
}

// Show the amount of times the commands are used through text
void commandTimesHistory(int times)
{

    cout << "Commands Typed: " << times << endl;
    cout << "" << endl;
    cout << "" << endl;
    return;
}