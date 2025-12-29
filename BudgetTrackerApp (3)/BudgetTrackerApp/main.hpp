#ifndef MAIN_HPP
#define MAIN_HPP

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

map<string, float> accounts = {{"college", 450},
                               {"children", 5},
                               {"entertainment", 100}};

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
#endif