#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>

#include <random>
#include <fstream>
#include <stdio.h>

#include "commands.hpp"
#include "dashboard.hpp"
#include "data.hpp"
#include "profile.hpp"
#include "randomization.hpp"

using namespace std;

void createAcc(string str, map<string, float> &acc)
{
    acc[str] = 0;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << str << " account has succesfully been made, starting off with $0" << endl;
    cout << "" << endl;
}
// Account removal
void removeAcc(string str, map<string, float> &acc)
{
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    // if the account dosesn't exists.
    if (acc.find(str) == acc.end())
    {
        cout << str << " doesn't exist, thus can't be removed" << endl;
        cout << "" << endl;
        return;
    }
    acc.erase(str);

    cout << str << " account has succesfully been removed. Have a good day!" << endl;
    cout << "" << endl;
}

void accountCreation(string str, map<string, float> &acc)
{
    vector<string> strs;
    string chars;
    stringstream ss(str);
    while (getline(ss, chars, ' '))
    {
        strs.push_back(chars);
    }
    vector<string> pieces = strs;

    if (pieces[0] == "create")
    {
        // If the account already exists. If not, create a new one.
        if (acc.find(pieces[1]) != acc.end())
        {
            cout << "This " << str << " account already exists" << endl;
            cout << "" << endl;
            return;
        }
        else
        {
            acc[pieces[1]] = 0;
            cout << str << " account has succesfully been made, starting off with $0" << endl;
        }
        createAcc(pieces[1], acc);
    }
    else if (pieces[0] == "remove")
    {
        removeAcc(pieces[1], acc);
    };

    cout << "" << endl;
    cout << "To leave this account, type in back or leave." << endl;
    cout << "" << endl;
}

void account(string str, double &wallet, map<string, float> &acc)
{
    char dash = '-';
    vector<string> strs;
    string chars;
    stringstream ss(str);
    while (getline(ss, chars, ' '))
    {
        strs.push_back(chars);
    }
    vector<string> pieces = strs;
    // If the account doesn't exists
    if (acc.find(pieces[1]) == acc.end())
    {
        cout << "" << endl;
        cout << "I am sorry, but this " << str << " account doesn't exist. Try again." << endl;
        cout << "" << endl;
        return;
    }
    cout << "" << endl;
    cout << "" << endl;
    cout << "You are in your account " << pieces[1] << endl;
    cout << "" << endl;
    cout << "> No command typed For any assistance, type g or guide for instructions (type in [back] or [leave] to leave if willing)" << endl;
    cout << "" << endl;
    while (true)
    {
        string typestr;
        bool isDigit = false;
        bool numVis = false;

        double nums;
        cout << "Type in " << pieces[1] << " account commands: ";
        // Seperate account command by two parts. The command and value
        getline(cin, typestr);
        vector<string> tokens;
        string token;
        stringstream ss(typestr);

        while (getline(ss, token, ' '))
        {
            tokens.push_back(token);
        }
        vector<string> parts = tokens;
        // If there are more than two data divided by whitespacing.
        if (parts.size() >= 2)
        {
            if (parts[1][0] == dash)
            {
                cout << "" << endl;
                cout << "" << endl;
                cout << "You can't have a number below 0" << endl;
                cout << "" << endl;
                continue;
            }
            // Divide the decimal data so that it can truncate and leave to two numbers after the decimal.
            int cut = parts[1].find(".");
            if (cut != -1 && parts[1].size() - cut > 2)
            {
                parts[1] = parts[1].substr(0, cut + 3);
            }

            for (int i = 0; i < parts[1].size(); i++)
            {

                if (!isdigit(parts[1][i]))
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
                continue;
            }
            nums = (stod(parts[1]));
        }
        if (parts[0] == "guide" || parts[0] == "g")
        {
            cout << "\n i/instruction --> "
                 << "show instructions \n"
                 << "rng/random --> Add money of a random amount into your wallet \n"
                 << "\n d/db/dboard/dashboard --> reveal account data and financial summaries "
                 << "create [account name] --> creates an account"
                 << "remove [remove name] --> removes an account"
                 << "\n account/acc [account name] --> view accounts (Must do this first before using commands below) "
                 << "\n \t - +/add (amount greater than -1) "
                 << "\n \t - -/sub/subtract (amount greater than -1, equal or less than the wallet's amount) "
                 << "\n \t g/guide --> show instructions and account command "
                 << "\n \t - sum/summary - show account's balance w/wallet --> show wallet amount "
                 << "\n \t - back/leave - leave account"
                 << "\n commandtimes/ct --> Show amount of times you entered something"
                 << "\n s/save --> saves data and convert into file"
                 << "\n exit/quit --> cease program  \n"
                 << endl;
            cout << "" << endl;
        }
        // Add command
        else if (parts[0] == "add" || parts[0] == "+")
        {
            deposit(pieces[1], nums, wallet, acc);
        }
        // Remove command
        else if (parts[0] == "sub" || parts[0] == "subtract" || parts[0] == "-")
        {
            withdraw(pieces[1], nums, wallet, acc);
        }
        // Summary command
        else if (parts[0] == "summary" || parts[0] == "sum")
        {
            cout << "----------" << endl;
            cout << "Total: $" << acc[pieces[1]] << endl;
            cout << "----------" << endl;
        }
        // exit account command
        else if (parts[0] == "back" || parts[0] == "leave")
        {
            cout << "" << endl;
            cout << "You have left your current account" << endl;
            cout << "" << endl;
            return;
        }
        else if (parts[0] == "d" || parts[0] == "db" || parts[0] == "dboard" || parts[0] == "dashboard")
        {
            dashboard(acc, wallet);
        }
        else if (parts[0] == "wallet" || parts[0] == "w")
        {
            cout << "Wallet amount: " << "$" << wallet << endl;
        }
        else
        {
            cout << "" << endl;
            cout << "" << endl;
            cout << "> No command typed. For any assistance, type g or guide for instructions (type in [back] or [leave] to leave if willing)" << endl;
            cout << "" << endl;
        }
        commandTimes();
    };
}
// Deposit account from money to wallet
void deposit(string str, double amount, double &wallet, map<string, float> &acc)
{
    cout << "" << endl;
    // If your wallet is less than the excepted amount your wanting to take from
    if (wallet < amount)
    {
        cout << "I am sorry but your wallet doesn't have that much money" << endl;
        cout << "" << endl;
        cout << "Actual wallet amount: $" << wallet << endl;
    }
    else
    {
        wallet -= amount;
        acc[str] += amount;
        cout << "" << endl;
        cout << "---------------------------------------" << endl;
        cout << "You have added $" << amount << " to " << str << endl;
        cout << str << " account amount: $" << acc[str] << endl;
        cout << "Wallet amount: $" << wallet << endl;
        cout << "---------------------------------------" << endl;
    }
    cout << "" << endl;
    return;
}
// Withdraw money from account to wallet
void withdraw(string str, double amount, double &wallet, map<string, float> &acc)
{
    cout << "" << endl;
    double originalvalue = acc[str];
    // If the account is less than the excepted amount your wanting to take from
    if (acc[str] < amount)
    {
        cout << "I am sorry but your " << str << " account doesn't have that much money" << endl;
        cout << "" << endl;
        cout << "Actual wallet amount: $" << wallet << endl;
    }
    else
    {
        wallet += amount;
        acc[str] -= amount;
        cout << "" << endl;
        cout << "---------------------------------------" << endl;
        cout << "You have added $" << amount << " to your wallet" << endl;
        cout << " Your wallet amount now: $" << wallet << endl;
        cout << "account amount from " << originalvalue << " now to: $" << acc[str] << endl;
        cout << "---------------------------------------" << endl;
    }
    cout << "" << endl;
    return;
}

// Entire Profile functionality
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
void deposit(string str, double amount, double &wallet, map<string, float> &acc)
{
    cout << "" << endl;
    // If your wallet is less than the excepted amount your wanting to take from
    if (wallet < amount)
    {
        cout << "I am sorry but your wallet doesn't have that much money" << endl;
        cout << "" << endl;
        cout << "Actual wallet amount: $" << wallet << endl;
    }
    else
    {
        wallet -= amount;
        acc[str] += amount;
        cout << "" << endl;
        cout << "---------------------------------------" << endl;
        cout << "You have added $" << amount << " to " << str << endl;
        cout << str << " account amount: $" << acc[str] << endl;
        cout << "Wallet amount: $" << wallet << endl;
        cout << "---------------------------------------" << endl;
    }
    cout << "" << endl;
    return;
}
// Withdraw money from account to wallet
void withdraw(string str, double amount, double &wallet, map<string, float> &acc)
{
    cout << "" << endl;
    double originalvalue = acc[str];
    // If the account is less than the excepted amount your wanting to take from
    if (acc[str] < amount)
    {
        cout << "I am sorry but your " << str << " account doesn't have that much money" << endl;
        cout << "" << endl;
        cout << "Actual wallet amount: $" << wallet << endl;
    }
    else
    {
        wallet += amount;
        acc[str] -= amount;
        cout << "" << endl;
        cout << "---------------------------------------" << endl;
        cout << "You have added $" << amount << " to your wallet" << endl;
        cout << " Your wallet amount now: $" << wallet << endl;
        cout << "account amount from " << originalvalue << " now to: $" << acc[str] << endl;
        cout << "---------------------------------------" << endl;
    }
    cout << "" << endl;
    return;
}

// Deposit account from money to wallet
void deposit(string str, double amount, double &wallet, map<string, float> &acc)
{
    cout << "" << endl;
    // If your wallet is less than the excepted amount your wanting to take from
    if (wallet < amount)
    {
        cout << "I am sorry but your wallet doesn't have that much money" << endl;
        cout << "" << endl;
        cout << "Actual wallet amount: $" << wallet << endl;
    }
    else
    {
        wallet -= amount;
        acc[str] += amount;
        cout << "" << endl;
        cout << "---------------------------------------" << endl;
        cout << "You have added $" << amount << " to " << str << endl;
        cout << str << " account amount: $" << acc[str] << endl;
        cout << "Wallet amount: $" << wallet << endl;
        cout << "---------------------------------------" << endl;
    }
    cout << "" << endl;
    return;
}