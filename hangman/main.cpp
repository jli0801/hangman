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
word usersWord; //default construtor is called
bool won; 
bool restart;

//features
void start_menu(string &word);
void newWord(string& word);
void updateBoard(word user); //changing game_start to func as a update board 
void init();


int main()
{
	char inputUser;
	//start of the initializer
	won = false;
	tries = 0; //max is 6 
	guessPointer = 0; //max is 26

	//open start menu, choose a file, and pick a word from file to input into wordchosen
	restart = false;

	start_menu(wordChosen);
	//have to input a word from a file before populate word can be used in update board
	word usersWord = word(wordChosen);
	//cout << usersWord.getWord() << endl;
	updateBoard(usersWord);
	while (!won) {
		
		if (restart)
		{
			newWord(wordChosen);
		}
		
		cout << "\nGuess a letter/word: " << endl;
		cin >> inputUser; //could be a char or word
		system("cls");
		//cout << usersWord.getWord();
		if (usersWord.setValues(inputUser) && (check_guesses(inputUser, guesses)))
		{
			//they found a letter or word from the chosen word
			guesses[guessPointer] = inputUser;
			guessPointer++;
			updateBoard(usersWord);

		}
		else
		{
			//increment and store the guesses/misses
			guesses[guessPointer] = inputUser;
			guessPointer++;
			misses[tries] = inputUser; //CHANGE THIS LATER SO WE CAN TAKE IN MULTIPLE LETTERED WORDS
			tries++;	
			updateBoard(usersWord);

		}

		//ALWAYS CHECK IF THE GAME IS DONE BY THE END
		if (usersWord.checkWholeWord())
		{
			won = true;
			//if won is true and we want to prompt user if they want to play again
			if (won) {
				int userChoice = 0;
				system("cls");
				cout << "\nWould you like to play again?\n1. Yes\n2. No\nChoice: " << endl;
				cin >> userChoice;
				switch (userChoice) {
				case 1:
					//user will play again
					
					init();
					system("cls"); //clear
					//restart = true;
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



void init()
{
	//initialize variables 
	won = false;
	tries = 0; //max is 6 
	guessPointer = 0; //max is 26
	for (int i = 0; i < sizeof(guesses); i++)
	{
		guesses[i] = NULL;
	}
	for (int j = 0; j < sizeof(misses); j++)
	{
		misses[j] = NULL;
	}
	//end of initialize 
}

void newWord(string& wordIn)
{
	int input;
	ifstream myFile;
	wordIn = loadRandomWord("wordset.txt");
	word usersWord = word(wordChosen);
	system("cls");
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
	printMessage("2. Medium", false, false);
	printMessage("3. Hard", false, true);
	cout << "Please select a number to continue, enter 'q' to quit: ";
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
		exit(0);
		break;
	case 3: 
		//HARD
		cout << "This section of the game has not been implemented. " << endl;
		exit(0);

		break;
	case 'Q':
	case 'q':
		cout << "GoodBye!" << endl;
		exit(0);	//exit the program 
		break;
	default:
		exit(0);
		break;
	}
}

void updateBoard(word user) //changed the function so that it can handle updates 
{
	string wordOutput = user.populateWord();
	printMessage("Hangman", true, false);
	printMessage("|", true, false);
	if (misses[0] != NULL && tries == 1)
	{
		printMessage("o", false, false); //head
		printMessage("", false, false);
		printMessage("", false, false);
	}
	else if (misses[1] != NULL && tries == 2)
	{
		printMessage("o", false, false);
		printMessage(" |", false, false); //body
		printMessage("", false, false);
	}
	else if (misses[2] != NULL && tries == 3)
	{
		printMessage("o", false, false);
		printMessage(" |", false, false); //left arm IDK IF THE SYNTAX RIGHT
		printMessage("", false, false);
	}
	else if (misses[3] != NULL && tries == 4)
	{
		printMessage("o", false, false);
		printMessage("/|\\", false, false); //BODY LEFT AND RIGHT ARM
		printMessage("", false, false);
	}
	else if (misses[4] != NULL && tries == 5)
	{
		printMessage("o", false, false);
		printMessage("/|\\", false, false); 
		printMessage("\\", false, false);	//left foot
	}
	else if(misses[5] != NULL && tries == 6)
	{
		printMessage("o", false, false);
		printMessage("/|\\", false, false);
		printMessage("/ \\", false, false);	//WHOLE BODY
	}
	else
	{
		printMessage("", false, false); //keep it blank
		printMessage("", false, false);
		printMessage("", false, false);
	}
	printMessage(wordOutput, true, true );
	cout << "\nGuesses: ";
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
	cout << "\nMisses: ";
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
	int m = 0;
	for (int i = 0; i < sizeof(misses); i++) {
		if (misses[i] != NULL)
			m++;
	}
	if (m == 6) {
		cout << "\n";
		printMessage("     YOU LOSE:(     ",true,true);
		cout << "\n";
		exit(0);
	}

}

