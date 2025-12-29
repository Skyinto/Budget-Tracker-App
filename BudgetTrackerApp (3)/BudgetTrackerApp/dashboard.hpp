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
#include "data.hpp"
#include "profile.hpp"
#include "randomization.hpp"


using namespace std;

void dashboard(map<string, float> &acc, double &wallet)
{
    double summary = 0;
    int count = 0;
    cout << "-----------------" << endl;
    cout << "|Account Summary|" << endl;
    cout << "-------------------------------------" << endl;
    cout << "" << endl;
    for (const auto &pair : acc)
    {
        cout << pair.first << ": " << "$" << pair.second << endl;
        summary += pair.second;
        count++;
    };
    cout << "" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Amount of accounts: " << count << endl;
    cout << "Account amount summmary: " << "$" << summary << endl;
    cout << "Wallet amount: " << "$" << wallet << endl;
    cout << "-------------------------------------" << endl;
}