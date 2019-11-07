#include "utilities.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include <cstring>

using namespace std;

void printMessage(string message, bool printTop, bool printBottom)
{
	if (printTop)
	{
		cout << "+---------------------------------+" << endl;
		cout << "|";
	}
	else
	{
		cout << "|";
	}
	bool front = true;
	for (auto i = message.length(); i < 33; i++)
	{
		if (front)
		{
			message = " " + message;
		}
		else
		{
			message = message + " ";
		}
		front = !front;
	}
	cout << message.c_str();

	if (printBottom)
	{
		cout << "|" << endl;
		cout << "+---------------------------------+" << endl;
	}
	else
	{
		cout << "|" << endl;
	}
}

string loadRandomWord(string path)
{
	srand(time(0));
	string word;
	vector<string> v;
	ifstream file(path);
	if (file.is_open())
	{
		while (getline(file, word))
			v.push_back(word);
		word = v[rand() % v.size()];
		file.close();
	}
	return word;
}

bool check_guesses(char input, char guesses[])//checks to see if the new user input has been already guessed
{
	for (int i = 0; i < sizeof(guesses); i++) {
		if (input == guesses[i]) //if the user inputs an already guessed letter, they will be asked to make a new guess and this will not count as a guess
			return false;
	}
	return true;//if not already guessed, can proceed to game
}


