#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "utilities.h"
#include "word.h"

using namespace std;

//variables 
char guesses[26]; //can handle up to 100 guesses
//guesses are the right letters
char misses[6]; //so it can handle up to 100 misses
//misses are the wrong letters 
int tries = 6;
string wordChosen;
word usersWord = word(wordChosen);
bool won; 

//features
void start_menu();
void game_start();
bool check(char input);


int main()
{
	wordChosen = loadRandomWord("wordset.txt");
	won = false; 
	if (!won)
	{
		start_menu();
		//game_start();
		cout << "Guess a letter" << endl;
	}
	else
	{
		//print: 
		//either they win or lose 

	}
}

bool check(char input)
{
	//placeholder for now
	return false;
}

void start_menu() {
	int input;
	printMessage("Hangman Game", true, false);
	printMessage("ESE224 Fall 2019", true, false);
	printMessage("Group Members:", true, false);
	printMessage("Student A", false, false);
	printMessage("Student B", false, false);
	printMessage("Student C", false, false);
	printMessage("Student D", false, true);
	printMessage("Select Difficulty:", false, false);
	printMessage("1. Easy", false, false);
	printMessage(" 2. Medium", false, false);
	printMessage("3. Hard", false, true);
	cout << "Please select a number to contune, enter 'q' to quit: ";
	cin >> input;
	switch (input) {
	case 1:
		//tries = 6;
		//wordChosen = loadRandomWord;
		//won = fail
		break;
	case 2:
		
		break;
	case 3: 

		break;
	default:
		break;
	}

}

void game_start()
{
	string wordOutput = usersWord.populateWord(usersWord.getWord());
	printMessage("Hangman", true, false);
	printMessage("|", true, false);
	printMessage("", false, false);
	printMessage("", false, false);
	printMessage("", false, false);
	printMessage(wordOutput, true, true );
	cout << "Guesses: ";
	for (int i = 0; i < 100; i++)
	{
		if (guesses[i] != NULL)
		{
			cout << guesses[i];
			if (i < 99)
			{
				if (guesses[i + 1] == NULL)
				{
					cout << endl;
					break; 
					//the next element is blank so 
					//don't print it 
				}
			}
		}
	}

	cout << "Misses: ";
	for (int j = 0; j < 100; j++)
	{
		if (misses[j] != NULL)
		{
			cout << misses[j];
			if (j < 99)
			{
				if (misses[j+1] == NULL)
				{
					cout << endl;
					break;
					//the next element is blank
					//so break out of it 
				}
			}
			
		}
	}
}