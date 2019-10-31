#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "utilities.h"
using namespace std;

char guesses[100]; //can handle up to 100 guesses
char misses[100]; //so it can handle up to 100 misses
int tries;
string wordChosen;
bool won; 

int main()
{
	tries = 6; //only get six tries 
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

}



void menu()
{
	printMessage("Hangman", true, false);
	printMessage("|", true, false);
	printMessage("", false, false);
	printMessage("", false, false);
	printMessage("", false, false);
	printMessage("_ _ _ _ _ _", true, true );
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