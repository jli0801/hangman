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
void menu();
bool check(char input);


int main()
{
	wordChosen = loadRandomWord("wordset.txt");
	won = false; 
	if (!won)
	{
		menu();
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



void menu()
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