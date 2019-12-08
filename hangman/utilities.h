#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include <list> 
#include <cstring>
#include "User.h"
using namespace std;

list<User> allUsers; 

void printMessage(string, bool, bool);

string loadRandomWord(string);

bool check_guesses(char,char[]);

void loadFile();

void updateFile(User u);
