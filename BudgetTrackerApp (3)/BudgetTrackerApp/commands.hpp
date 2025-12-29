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
#include "dashboard.hpp"
#include "data.hpp"
#include "profile.hpp"
#include "randomization.hpp"

using namespace std;

void commands(string msg, double &wallet, map<string, float> &acc, string pfp)
{

    cout << "" << endl;
    bool commandPlayed = false;
    ;
    if (msg == "guide" || msg == "g")
    {
        // function command for bottom line, preferably in a map
        cout << "" << endl;
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
    else if (msg == "instruction" || msg == "i")
    {
        // Instruciton lists
        cout << "" << endl;
        cout << "This is a budget tracking software."
             << "\n - Every profile has a wallet with $500 by default."
             << "\n - For more money, you can generate some to add into your wallet using the rng or random commands"
             << "\n - With that money, you can import it into your account(s), or extract money from those account(s) into your wallet."
             << "\n - If your interested in viewing your account data and summary, you can open your dashboard to view it."
             << "\n - Finally you are allowed to either quit or save this program. If saved, your account info will be saved in a text file. The account data can regenerate if the profile name typed matches the text file"
             << "\n - If you delete or the administative textfile (not the textfile where your account data will be saved in a well-structured format), then the saved data will stop working"
             << "\n - You can reopen these instructions by typing in instruction or i in the prompt."
             << "\n - Suggest to keep both the same name of the regular textfile and administrative one."
             << "\n - For the list of commands, type in guide or g." << endl;
        cout << "" << endl;
    }
    else if (msg.substr(0, 8) == "account " || msg.substr(0, 4) == "acc ")
    {
        account(msg, wallet, acc);
    }
    else if (msg.substr(0, 7) == "create " || msg.substr(0, 7) == "remove ")
    {
        accountCreation(msg, acc);
    }
    else if (msg == "d" || msg == "db" || msg == "dboard" || msg == "dashboard")
    {
        // Show Dashboard
        dashboard(acc, wallet);
    }
    else if (msg == "wallet" || msg == "w")
    {
        // Show Wallet
        cout << "Wallet amount: " << "$" << wallet << endl;
    }
    else if (msg == "random" || msg == "rng")
    {
        // Show Random Functionality
        typeRandom(wallet);
    }
    else if (msg == "commandtimes" || msg == "ct")
    {
        // Show Random command times
        commandTimesHistory(commandTimes());
        commandPlayed = true;
    }
    // Show Random save data
    else if (msg == "save" || msg == "s")
    {
        saveData(pfp, acc, wallet);
    }
    // Prevents it from playing again since commandTimesHistory(commandTimes()) would already have increase it.
    if (!commandPlayed)
    {
        commandTimes();
    }
};