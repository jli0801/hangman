#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include <cstring>
using namespace std;

void printMessage(string, bool, bool);

string loadRandomWord(string);

bool check_guesses(char,int);

bool check_answer(char,string);