#include "utilities.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include <cstring>

using namespace std;
//PRINT MESSAGE 
//PURPOSE: Prints a message with the template provided
void printMessage(string message, bool printTop, bool printBottom)
{
	if (printTop)
	{
		cout << "\n+---------------------------------+" << endl;
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
//LOAD RANDOM WORD
//PURPOSE: Uses the input to find a txt file and randomizes to get a word 
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

//CHECK GUESSES
//Purpose: CHECKS TO SEE IF THE USER INPUT HAS ALREADY BEEN USED 
bool check_guesses(char input, char guesses[])//checks to see if the new user input has been already guessed
{
	if (!((input>='a'&&input<='z')||(input>='A'&&input<='Z')))
		return false;
	for (int i = 0; i < sizeof(guesses); i++) {
		if (input == guesses[i]) //if the user inputs an already guessed letter, they will be asked to make a new guess and this will not count as a guess
			return false;
	}
	return true;//if not already guessed, can proceed to game
}






