#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "utilities.h"
#include "word.h"

using namespace std;

//variables 
//GUESSES ARE ALL INPUTS 
char guesses[26]; //can handle up to 26 guesses
int guessPointer;
//guesses are the right letters & wrong 
char misses[6]; //so it can handle up to 6 misses
//misses are the wrong letters 
int tries;
string wordChosen;
word usersWord;
bool won; 
bool start;

//features
void start_menu(string &word);
void updateBoard(); //changing game_start to func as a update board 
//void game_start(istream& in); //have the user guess in a word and update the guesses and misses.

int main()
{
	string inputUser = "";
	int userChoice = 0;
	//initialize variables 
	won = false; 
	start = true;
	tries = 0; //max is 6 
	guessPointer = 0; //max is 26
	
	while (!won) {
		start_menu(wordChosen);
		//if won is true and we want to prompt user if they want to play again

		updateBoard();

		cout << "Guess a letter/word: " << endl;

		cin >> inputUser; //could be a char or word
		//if (check_letter(inputUser) && check_word(inputUser))
		if (false)
		{
			//they found a letter or word from the chosen word
			updateBoard();
		}
		else
		{
			//increment and store the guesses/misses
			guesses[guessPointer] = inputUser.at(1);
			guessPointer++;
			misses[tries] = inputUser.at(1); //CHANGE THIS LATER SO WE CAN TAKE IN MULTIPLE LETTERED WORDS
			tries++;
			updateBoard(); //update board 


			if (won) {
				cout << "\nWould you like to play again?\n1. Yes\n2. No\nChoice: " << endl;
				cin >> userChoice;
				switch (userChoice) {
				case 1:
					//user will play again
					won = false;
					break;
				case 2:
					won = true;
					break;
				default:
					cerr << "Error, please try again" << endl;
					won = false;
					break;
				}

			}
		}
	}
}



void start_menu(string &word) {
	int input;
	ifstream myFile;

	printMessage("Hangman Game", true, false);
	printMessage("ESE224 Fall 2019", true, false);
	printMessage("Group Members:", true, false);
	printMessage("Jessica Li", false, false);
	printMessage("Dorothy Lee", false, false);
	printMessage("Lily Li", false, false);
	printMessage("Darren Li", false, true);
	printMessage("Select Difficulty:", false, false);
	printMessage("1. Easy", false, false);
	printMessage(" 2. Medium", false, false);
	printMessage("3. Hard", false, true);
	cout << "Please select a number to contune, enter 'q' to quit: ";
	cin >> input;
	switch (input) {
	case 1:
		//input file name here to be used for easy
		word = loadRandomWord("wordset.txt");
		system("cls");
		break;
	case 2:
		//MEDIUM
		cout << "This section of the game has not been implemented. " << endl; 
		break;
	case 3: 
		//HARD
		cout << "This section of the game has not been implemented. " << endl;
		break;
	case 'Q':
	case 'q':
		cout << "\nGoodBye!" << endl;
		exit(0);	//exit the program 
		break;
	default:
		break;
	}
}

void updateBoard() //changed the function so that it can handle updates 
{
	string wordOutput = usersWord.populateWord(usersWord.getWord());
	printMessage("Hangman", true, false);
	printMessage("|", true, false);
	if (guesses[0] != NULL && tries == 1)
	{
		printMessage("o", false, false); //head
		printMessage("", false, false);
		printMessage("", false, false);
	}
	else if (guesses[1] != NULL && tries == 2)
	{
		printMessage("o", false, false);
		printMessage("|", false, false); //body
		printMessage("", false, false);
	}
	else if (guesses[2] != NULL && tries == 3)
	{
		printMessage("o", false, false);
		printMessage("|'\'", false, false); //left arm IDK IF THE SYNTAX RIGHT
		printMessage("", false, false);
	}
	else if (guesses[3] != NULL && tries == 4)
	{
		printMessage(" o", false, false);
		printMessage("/|'\'", false, false); //BODY LEFT AND RIGHT ARM
		printMessage("", false, false);
	}
	else if (guesses[4] != NULL && tries == 5)
	{
		printMessage(" o", false, false);
		printMessage("/|'\'", false, false); 
		printMessage("'\'", false, false);	//left foot
	}
	else if(guesses[5] != NULL && tries == 6)
	{
		printMessage(" o", false, false);
		printMessage("/|'\'", false, false);
		printMessage("/ '\'", false, false);	//WHOLE BODY
	}
	else
	{
		printMessage("", false, false); //keep it blank
		printMessage("", false, false);
		printMessage("", false, false);
	}
	printMessage(wordOutput, true, true );
	cout << "Guesses: ";
	for (int i = 0; i < sizeof(guesses); i++)
	{
		if (guesses[i] != NULL)
		{
			cout << guesses[i] << " "; //edited so it doesn't mesh together
			if (i < (sizeof(guesses) - 1))
			{
				if (guesses[i + 1] == NULL)
				{
					cout << endl;

					//the next element is blank so 
					//don't print it 
				}
			}
		}
	}
	cout << endl;
	cout << "Misses: ";
	for (int j = 0; j < sizeof(misses); j++)
	{
		if (misses[j] != NULL)
		{
			cout << misses[j] << " ";
			if (j < (sizeof(misses) - 1))
			{
				if (misses[j + 1] == NULL)
				{
					cout << endl;

					//the next element is blank
					//so break out of it 
				}
			}

		}
	}
}

