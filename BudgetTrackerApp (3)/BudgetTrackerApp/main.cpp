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

#include "main.hpp"
using namespace std;
map<string, float> accounts = {{"college", 450},
                               {"children", 5},
                               {"entertainment", 100}};
// Functionality and Components
string profile(string pfp, bool match, map<string, float> &acc);

void commands(string msg, double &wallet, map<string, float> &acc, string pfp = "");
void dashboard(map<string, float> &acc, double &wallet);
void account(string str, double &wallet, map<string, float> &acc);
void accountCreation(string str, map<string, float> &acc);
void deposit(string str, double amount, double &wallet, map<string, float> &acc);
void withdraw(string str, double amount, double &wallet, map<string, float> &acc);
// Default value added with rangenums = 100
void random(double &wallet, bool err, int rangenums = 100);
void typeRandom(double &wallet);
int commandTimes();
void commandTimesHistory(int times);
void saveData(string pfp, map<string, float> &acc, double &wallet);
void loadData(string pfp, double &wallet, map<string, float> &acc);

bool profileExists(string pfp);
// global map data
int main()
{

    string pfp;
    cout << "------------------" << endl;
    cout << "| Budget Tracker |" << endl;
    cout << "------------------" << endl;

    cout << endl;
    cout << endl;

    cout << "Type in your existing profile name. If it doesn't exist, you can create a new one by just typing." << endl;
    cout << "Name: ";
    cin >> pfp;
    // If the profile exist, return previous data. If not, then create a new one.
    if (profileExists(pfp))
    {
        profile(pfp, true, accounts);
    }
    else
    {
        profile(pfp, false, accounts);
    }

    return 0;
}

// void commands(string msg, double &wallet, map<string, float> &acc, string pfp)
// {

//     cout << "" << endl;
//     bool commandPlayed = false;
//     ;
//     if (msg == "guide" || msg == "g")
//     {
//         // function command for bottom line, preferably in a map
//         cout << "" << endl;
//         cout << "\n i/instruction --> "
//              << "show instructions \n"
//              << "rng/random --> Add money of a random amount into your wallet \n"
//              << "\n d/db/dboard/dashboard --> reveal account data and financial summaries "
//              << "create [account name] --> creates an account"
//              << "remove [remove name] --> removes an account"
//              << "\n account/acc [account name] --> view accounts (Must do this first before using commands below) "
//              << "\n \t - +/add (amount greater than -1) "
//              << "\n \t - -/sub/subtract (amount greater than -1, equal or less than the wallet's amount) "
//              << "\n \t g/guide --> show instructions and account command "
//              << "\n \t - sum/summary - show account's balance w/wallet --> show wallet amount "
//              << "\n \t - back/leave - leave account"
//              << "\n commandtimes/ct --> Show amount of times you entered something"
//              << "\n s/save --> saves data and convert into file"
//              << "\n exit/quit --> cease program  \n"
//              << endl;
//         cout << "" << endl;
//     }
//     else if (msg == "instruction" || msg == "i")
//     {
//         //Instruciton lists
//         cout << "" << endl;
//         cout << "This is a budget tracking software."
//              << "\n - Every profile has a wallet with $500 by default."
//              << "\n - For more money, you can generate some to add into your wallet using the rng or random commands"
//              << "\n - With that money, you can import it into your account(s), or extract money from those account(s) into your wallet."
//              << "\n - If your interested in viewing your account data and summary, you can open your dashboard to view it."
//              << "\n - Finally you are allowed to either quit or save this program. If saved, your account info will be saved in a text file. The account data can regenerate if the profile name typed matches the text file"
//              << "\n - If you delete or the administative textfile (not the textfile where your account data will be saved in a well-structured format), then the saved data will stop working"
//              << "\n - You can reopen these instructions by typing in instruction or i in the prompt."
//              << "\n - Suggest to keep both the same name of the regular textfile and administrative one."
//              << "\n - For the list of commands, type in guide or g." << endl;
//         cout << "" << endl;
//     }
//     else if (msg.substr(0, 8) == "account " || msg.substr(0, 4) == "acc ")
//     {
//         account(msg, wallet, acc);
//     }
//     else if (msg.substr(0, 7) == "create " || msg.substr(0, 7) == "remove ")
//     {
//         accountCreation(msg, acc);
//     }
//     else if (msg == "d" || msg == "db" || msg == "dboard" || msg == "dashboard")
//     {
//         //Show Dashboard
//         dashboard(acc, wallet);
//     }
//     else if (msg == "wallet" || msg == "w")
//     {
//         //Show Wallet
//         cout << "Wallet amount: " << "$" << wallet << endl;
//     }
//     else if (msg == "random" || msg == "rng")
//     {
//         //Show Random Functionality
//         typeRandom(wallet);
//     }
//     else if (msg == "commandtimes" || msg == "ct")
//     {
//         //Show Random command times
//         commandTimesHistory(commandTimes());
//         commandPlayed = true;
//     }
//     //Show Random save data
//     else if (msg == "save" || msg == "s")
//     {
//         saveData(pfp, acc, wallet);
//     }
//     //Prevents it from playing again since commandTimesHistory(commandTimes()) would already have increase it.
//     if (!commandPlayed)
//     {
//         commandTimes();
//     }
// };

// //Dashboard data
// void dashboard(map<string, float> &acc, double &wallet)
// {
//     double summary = 0;
//     int count = 0;
//     cout << "-----------------" << endl;
//     cout << "|Account Summary|" << endl;
//     cout << "-------------------------------------" << endl;
//     cout << "" << endl;
//     for (const auto &pair : acc)
//     {
//         cout << pair.first << ": " << "$" << pair.second << endl;
//         summary += pair.second;
//         count++;
//     };
//     cout << "" << endl;
//     cout << "-------------------------------------" << endl;
//     cout << "Amount of accounts: " << count << endl;
//     cout << "Account amount summmary: " << "$" << summary << endl;
//     cout << "Wallet amount: " << "$" << wallet << endl;
//     cout << "-------------------------------------" << endl;
// }
// //Account creation
// void createAcc(string str, map<string, float> &acc)
// {
//     acc[str] = 0;
//     cout << "" << endl;
//     cout << "" << endl;
//     cout << "" << endl;
//     cout << str << " account has succesfully been made, starting off with $0" << endl;
//     cout << "" << endl;
// }
// //Account removal
// void removeAcc(string str, map<string, float> &acc)
// {
//     cout << "" << endl;
//     cout << "" << endl;
//     cout << "" << endl;
//     //if the account dosesn't exists.
//     if (acc.find(str) == acc.end())
//     {
//         cout << str << " doesn't exist, thus can't be removed" << endl;
//         cout << "" << endl;
//         return;
//     }
//     acc.erase(str);

//     cout << str << " account has succesfully been removed. Have a good day!" << endl;
//     cout << "" << endl;
// }
// //Allow to create or delete accounts
// void accountCreation(string str, map<string, float> &acc)
// {
//     vector<string> strs;
//     string chars;
//     stringstream ss(str);
//     while (getline(ss, chars, ' '))
//     {
//         strs.push_back(chars);
//     }
//     vector<string> pieces = strs;

//     if (pieces[0] == "create")
//     {
//         //If the account already exists. If not, create a new one.
//         if (acc.find(pieces[1]) != acc.end())
//         {
//             cout << "This " << str << " account already exists" << endl;
//             cout << "" << endl;
//             return;
//         }
//         else
//         {
//             acc[pieces[1]] = 0;
//             cout << str << " account has succesfully been made, starting off with $0" << endl;
//         }
//         createAcc(pieces[1], acc);
//     }
//     else if (pieces[0] == "remove")
//     {
//         removeAcc(pieces[1], acc);
//     };

//     cout << "" << endl;
//     cout << "To leave this account, type in back or leave." << endl;
//     cout << "" << endl;
// }

// //Modify your account
// void account(string str, double &wallet, map<string, float> &acc)
// {
//     char dash = '-';
//     vector<string> strs;
//     string chars;
//     stringstream ss(str);
//     while (getline(ss, chars, ' '))
//     {
//         strs.push_back(chars);
//     }
//     vector<string> pieces = strs;
//     //If the account doesn't exists
//     if (acc.find(pieces[1]) == acc.end())
//     {
//         cout << "" << endl;
//         cout << "I am sorry, but this " << str << " account doesn't exist. Try again." << endl;
//         cout << "" << endl;
//         return;
//     }
//     cout << "" << endl;
//     cout << "" << endl;
//     cout << "You are in your account " << pieces[1] << endl;
//     cout << "" << endl;
//     cout << "> No command typed For any assistance, type g or guide for instructions (type in [back] or [leave] to leave if willing)" << endl;
//     cout << "" << endl;
//     while (true)
//     {
//         string typestr;
//         bool isDigit = false;
//         bool numVis = false;

//         double nums;
//         cout << "Type in " << pieces[1] << " account commands: ";
//         //Seperate account command by two parts. The command and value
//         getline(cin, typestr);
//         vector<string> tokens;
//         string token;
//         stringstream ss(typestr);

//         while (getline(ss, token, ' '))
//         {
//             tokens.push_back(token);
//         }
//         vector<string> parts = tokens;
//         //If there are more than two data divided by whitespacing.
//         if (parts.size() >= 2)
//         {
//             if (parts[1][0] == dash)
//             {
//                 cout << "" << endl;
//                 cout << "" << endl;
//                 cout << "You can't have a number below 0" << endl;
//                 cout << "" << endl;
//                 continue;
//             }
//             //Divide the decimal data so that it can truncate and leave to two numbers after the decimal.
//             int cut = parts[1].find(".");
//             if (cut != -1 && parts[1].size() - cut > 2)
//             {
//                 parts[1] = parts[1].substr(0, cut + 3);
//             }

//             for (int i = 0; i < parts[1].size(); i++)
//             {

//                 if (!isdigit(parts[1][i]))
//                 {
//                     cout << "" << endl;
//                     cout << "" << endl;
//                     cout << "The value must only contain numbers";
//                     cout << "" << endl;
//                     cout << "" << endl;
//                     cout << "" << endl;
//                     numVis = true;
//                     break;
//                 }
//             }
//             if (numVis)
//             {
//                 continue;
//             }
//             nums = (stod(parts[1]));
//         }
//         if (parts[0] == "guide" || parts[0] == "g")
//         {
//             cout << "\n i/instruction --> "
//                  << "show instructions \n"
//                  << "rng/random --> Add money of a random amount into your wallet \n"
//                  << "\n d/db/dboard/dashboard --> reveal account data and financial summaries "
//                  << "create [account name] --> creates an account"
//                  << "remove [remove name] --> removes an account"
//                  << "\n account/acc [account name] --> view accounts (Must do this first before using commands below) "
//                  << "\n \t - +/add (amount greater than -1) "
//                  << "\n \t - -/sub/subtract (amount greater than -1, equal or less than the wallet's amount) "
//                  << "\n \t g/guide --> show instructions and account command "
//                  << "\n \t - sum/summary - show account's balance w/wallet --> show wallet amount "
//                  << "\n \t - back/leave - leave account"
//                  << "\n commandtimes/ct --> Show amount of times you entered something"
//                  << "\n s/save --> saves data and convert into file"
//                  << "\n exit/quit --> cease program  \n"
//                  << endl;
//             cout << "" << endl;
//         }
//         //Add command
//         else if (parts[0] == "add" || parts[0] == "+")
//         {
//             deposit(pieces[1], nums, wallet, acc);
//         }
//         //Remove command
//         else if (parts[0] == "sub" || parts[0] == "subtract" || parts[0] == "-")
//         {
//             withdraw(pieces[1], nums, wallet, acc);
//         }
//         //Summary command
//         else if (parts[0] == "summary" || parts[0] == "sum")
//         {
//             cout << "----------" << endl;
//             cout << "Total: $" << acc[pieces[1]] << endl;
//             cout << "----------" << endl;
//         }
//         //exit account command
//         else if (parts[0] == "back" || parts[0] == "leave")
//         {
//             cout << "" << endl;
//             cout << "You have left your current account" << endl;
//             cout << "" << endl;
//             return;
//         }
//         else if (parts[0] == "d" || parts[0] == "db" || parts[0] == "dboard" || parts[0] == "dashboard")
//         {
//             dashboard(acc, wallet);
//         }
//         else if (parts[0] == "wallet" || parts[0] == "w")
//         {
//             cout << "Wallet amount: " << "$" << wallet << endl;
//         }
//         else
//         {
//             cout << "" << endl;
//             cout << "" << endl;
//             cout << "> No command typed. For any assistance, type g or guide for instructions (type in [back] or [leave] to leave if willing)" << endl;
//             cout << "" << endl;
//         }
//         commandTimes();
//     };
// }
// //Deposit account from money to wallet
// void deposit(string str, double amount, double &wallet, map<string, float> &acc)
// {
//     cout << "" << endl;
//     //If your wallet is less than the excepted amount your wanting to take from
//     if (wallet < amount)
//     {
//         cout << "I am sorry but your wallet doesn't have that much money" << endl;
//         cout << "" << endl;
//         cout << "Actual wallet amount: $" << wallet << endl;
//     }
//     else
//     {
//         wallet -= amount;
//         acc[str] += amount;
//         cout << "" << endl;
//         cout << "---------------------------------------" << endl;
//         cout << "You have added $" << amount << " to " << str << endl;
//         cout << str << " account amount: $" << acc[str] << endl;
//         cout << "Wallet amount: $" << wallet << endl;
//         cout << "---------------------------------------" << endl;
//     }
//     cout << "" << endl;
//     return;
// }
// //Withdraw money from account to wallet
// void withdraw(string str, double amount, double &wallet, map<string, float> &acc)
// {
//     cout << "" << endl;
//     double originalvalue = acc[str];
//     //If the account is less than the excepted amount your wanting to take from
//     if (acc[str] < amount)
//     {
//         cout << "I am sorry but your " << str << " account doesn't have that much money" << endl;
//         cout << "" << endl;
//         cout << "Actual wallet amount: $" << wallet << endl;
//     }
//     else
//     {
//         wallet += amount;
//         acc[str] -= amount;
//         cout << "" << endl;
//         cout << "---------------------------------------" << endl;
//         cout << "You have added $" << amount << " to your wallet" << endl;
//         cout << " Your wallet amount now: $" << wallet << endl;
//         cout << "account amount from " << originalvalue << " now to: $" << acc[str] << endl;
//         cout << "---------------------------------------" << endl;
//     }
//     cout << "" << endl;
//     return;
// }

// //Entire Profile functionality
// string profile(string pfp, bool match, map<string, float> &acc)
// {
//     // Set wallet and hasQuit data
//     double wallet = 500;
//     bool hasQuit = true;
//     if (match)
//     {
//         loadData(pfp, wallet, acc);
//     }
//     // Introduce the profile and show the instructions
//     cout << "" << endl;
//     cout << "" << endl;
//     cout << "Welcome " << (match ? "back " : "") << pfp << endl;
//     commands("i", wallet, accounts);
//     //
//     do
//     {
//         string prompt;

//         cout << "> For any assistance, type g or guide for instructions" << endl;
//         cout << endl;
//         cout << "Type text " << pfp << ">: ";
//         getline(cin, prompt);
//         commands(prompt, wallet, accounts, pfp);

//         if (prompt == "quit" || prompt == "exit")
//             hasQuit = false;

//     } while (hasQuit);
//     //Ending
//     cout << "You have exited the program, thank you for this pleasent experience " << pfp << endl;
//     return pfp;
// }
// //Randomize prompt function
// void typeRandom(double &wallet)
// {
//     string range;

//     while (true)
//     {
//         cout << "Type in wallet number range under 1001 and above 0 (leave/back/quit to quit): ";
//         cin >> range;
//         bool numVis = false;
//         // Need array loop according to the project description. Given strings are basically arrays, it works doesn't it?
//         if (range == "quit" || range == "leave" || range == "back")
//         {
//             break;
//         }
//         //Check input validation
//         for (char c : range)
//         {

//             if (!isdigit(c))
//             {
//                 cout << "" << endl;
//                 cout << "" << endl;
//                 cout << "The value must only contain numbers";
//                 cout << "" << endl;
//                 cout << "" << endl;
//                 cout << "" << endl;
//                 numVis = true;
//                 break;
//             }
//         }

//         if (numVis)
//         {
//             random(wallet, true);
//         }
//         else if (stod(range) > 0 && stod(range) <= 1000)
//         {
//             random(wallet, false, stod(range));
//         }
//         else
//         {
//             random(wallet, true);
//         };
//         commandTimes();
//     };
//     cout << "" << endl;
//     cout << "You have left the randomization program" << endl;
//     cout << "" << endl;
//     return;
// }

// //Randomize the money amount to add onto wallet
// void random(double &wallet, bool err, int rangenums)
// {
//     //If the input validation is invalid, the range will be set to 100 by default
//     //Randomize from 1 - 1000
//     srand(time(0));
//     int rng = rand() % (rangenums) + 1;
//     wallet += rng;
//     cout << "" << endl;
//     cout << "-----------------------" << endl;
//     if (err)
//     {
//         cout << "Since your input is incorrect, your given a range of 100 by default" << endl;
//         cout << "" << endl;
//     }
//     cout << "+ $" << rng << endl;
//     cout << "Your wallet now has: $ " << wallet << endl;
//     cout << "-----------------------" << endl;
//     cout << "" << endl;
//     return;
// }

// // Amount of times the commands are used
// int commandTimes()
// {

//     // Just to add Enums as I don't know where else to add them
//     enum Counts
//     {
//         TIMES = 0
//     };
//     enum Counts t = TIMES;
//     static int timeNums = t;
//     timeNums++;
//     return timeNums;
// }

// // Show the amount of times the commands are used through text
// void commandTimesHistory(int times)
// {

//     cout << "Commands Typed: " << times << endl;
//     cout << "" << endl;
//     cout << "" << endl;
//     return;
// }

// // Save Data Function

// void saveData(string pfp, map<string, float> &acc, double &wallet)
// {
//     double summary = 0;
//     int count = 0;
//     string pfpnameFile = pfp + ".txt";
//     string pfpnameAdmin = pfp + "_administration.txt";
//     ofstream pfpfile(pfpnameFile);
//     ofstream pfpAdminfile(pfpnameAdmin);
//     pfpfile << "------------------------------------------------\n";
//     pfpfile << "\n";
//     pfpfile << pfp << " profile account data \n";
//     pfpfile << "\n";
//     pfpfile << "------------------------------------------------\n";
//     pfpfile << "\n";
//     pfpAdminfile << wallet << "\n";
//     //Add each key/value pair into text file
//     for (const auto &pair : acc)
//     {
//         pfpfile << pair.first << ": $" << pair.second << "\n";
//         pfpAdminfile << pair.first << "\n";
//         pfpAdminfile << pair.second << "\n";
//         summary += pair.second;
//         count++;
//     };

//     pfpfile << "\n";
//     pfpfile << "\n";
//     pfpfile << "\n";

//     pfpfile << "-------------------------------------\n";
//     pfpfile << "Amount of accounts: " << count << "\n";
//     pfpfile << "Account amount summmary: " << "$" << summary << endl;
//     pfpfile << "Wallet amount: " << "$" << wallet << endl;
//     pfpfile << "-------------------------------------" << endl;

//     pfpfile.close();
//     pfpAdminfile.close();

//     return;
// }

// //Check if the profile textfile exists
// bool profileExists(string pfp)
// {
//     string pfpnamefile = pfp + "_administration.txt";
//     ifstream pfpfile(pfpnamefile);
//     if (pfpfile.is_open())
//     {
//         return true;
//     }
//     return false;
// }

// //Loading the Data from the file
// void loadData(string pfp, double &wallet, map<string, float> &acc)
// {
//     acc.clear();
//     cout << pfp << endl;
//     int n = 0;
//     int num = 0;
//     string data;
//     string key;
//     //Matching the file
//     string pfpfilename = pfp + "_administration.txt";
//     ifstream pfpfile(pfpfilename);
//     int evenodd = false;
//     bool line = true;
//     //Adding data into the account map
//     while (pfpfile >> data)
//     {

//         if (line)
//         {
//             wallet = stod(data);
//             line = false;
//             continue;
//         }
//         else
//         {
//             if (evenodd)
//             {
//                 acc[key] = stod(data);
//                 evenodd = false;
//             }
//             else
//             {
//                 acc[data] = 0;
//                 evenodd = true;
//             }
//         }
//         cout << data << endl;

//         key = data;
//     }
//     pfpfile.close();
//     return;
// }