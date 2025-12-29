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
#include "profile.hpp"
#include "randomization.hpp"
using namespace std;

void saveData(string pfp, map<string, float> &acc, double &wallet)
{
    double summary = 0;
    int count = 0;
    string pfpnameFile = pfp + ".txt";
    string pfpnameAdmin = pfp + "_administration.txt";
    ofstream pfpfile(pfpnameFile);
    ofstream pfpAdminfile(pfpnameAdmin);
    pfpfile << "------------------------------------------------\n";
    pfpfile << "\n";
    pfpfile << pfp << " profile account data \n";
    pfpfile << "\n";
    pfpfile << "------------------------------------------------\n";
    pfpfile << "\n";
    pfpAdminfile << wallet << "\n";
    // Add each key/value pair into text file
    for (const auto &pair : acc)
    {
        pfpfile << pair.first << ": $" << pair.second << "\n";
        pfpAdminfile << pair.first << "\n";
        pfpAdminfile << pair.second << "\n";
        summary += pair.second;
        count++;
    };

    pfpfile << "\n";
    pfpfile << "\n";
    pfpfile << "\n";

    pfpfile << "-------------------------------------\n";
    pfpfile << "Amount of accounts: " << count << "\n";
    pfpfile << "Account amount summmary: " << "$" << summary << endl;
    pfpfile << "Wallet amount: " << "$" << wallet << endl;
    pfpfile << "-------------------------------------" << endl;

    cout << "---------------------------------------------------" << endl;
    cout << "" << endl;
    cout << "Your financial data has been saved in a " << pfp << "textfile.\n"
         << "Take a look in the file explorer under this folder. There is another textfile that's administrative and uses the same name.\n"
         << "Don't touch that, unless your purposly modify in a way that you know what your doing."
         << " Take care!" << endl;
    cout << "------------------------------------" << endl;

    cout << "" << endl;
    cout << "" << endl;
    pfpfile.close();
    pfpAdminfile.close();

    return;
}

// Check if the profile textfile exists
bool profileExists(string pfp)
{
    string pfpnamefile = pfp + "_administration.txt";
    ifstream pfpfile(pfpnamefile);
    if (pfpfile.is_open())
    {
        return true;
    }
    return false;
}

// Loading the Data from the file
void loadData(string pfp, double &wallet, map<string, float> &acc)
{
    acc.clear();
    cout << pfp << endl;
    int n = 0;
    int num = 0;
    string data;
    string key;
    // Matching the file
    string pfpfilename = pfp + "_administration.txt";
    ifstream pfpfile(pfpfilename);
    int evenodd = false;
    bool line = true;
    // Adding data into the account map
    while (pfpfile >> data)
    {

        if (line)
        {
            wallet = stod(data);
            line = false;
            continue;
        }
        else
        {
            if (evenodd)
            {
                acc[key] = stod(data);
                evenodd = false;
            }
            else
            {
                acc[data] = 0;
                evenodd = true;
            }
        }
        cout << data << endl;

        key = data;
    }
    pfpfile.close();
    return;
}