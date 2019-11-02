#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "utilities.h"
#include "word.h"

using namespace std;

//variables 
string guesses[32]; //can handle up to 32 guesses (26 letters in alphabet + 6 misses of guessed words/phrases)
//guesses are the right letters
string misses[6]; //so it can handle up to 6 misses
//misses are the wrong letters 

string wordChosen;
word usersWord = word(wordChosen);
bool won; 

//features
void menu();
bool check_guesses(string input); //checks if the user input has already been guessed
bool check_word(string input); // checks if user input is a correct attempt



//=============================================================================//
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

bool check_guesses(string input)
{
	for (int i = 0; i < 32; i++) {
		if ((input.compare(guesses[i])) == 0) {
			cout << "Already guessed this attempt, please enter another guess";
			return false;
		}
	}
	return true;
}

bool check_word(string input)
{
	for (int i = 0; i < wordChosen.length(); i++) {
		if (wordChosen.compare(input) == 0) {
		}
	}

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