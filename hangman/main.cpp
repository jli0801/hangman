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
void start_menu();
void updateBoard(); //changing game_start to func as a update board 

bool check_guesses(string input);
bool check_word(string input);



int main()
{
	//initialize variables 
	won = false; 
	start = true;
	tries = 0; //max is 6 
	guessPointer = 0; //max is 26
	
		if (start)
		{
			start_menu();
			start = false; 
			//THIS WILL BECOME TRUE WHEN THEY'RE DONE WITH A GAME
		}
		else
		{
			//start the game 
			wordChosen = loadRandomWord("wordset.txt");
			usersWord = word(wordChosen);
			updateBoard();
			while (!won)
			{
				cout << "Guess a letter/word." << endl;
				string inputUser;
				cin >> inputUser; //could be a char or word
				if (check_guesses(inputUser) && check_word(inputUser))
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

				}
			}
			//when it gets out of the loop you need to prompt the user if they want to start again + tell them if they lost or won
		}
	
	
}

bool check_guesses(string input)
{
	for (int i = 0; i < sizeof(guesses); i++) {
		//guesses are chars not strings so don't use .compare
		if (input.at(0) == guesses[i]) {
			cout << "Already guessed this attempt, please enter another guess";
			return false;
		}
	}
	return true;
}

bool check_word(string input)
{
	//don't need the for loop	
	if (wordChosen.compare(input) == 0) {
		return true; 
	}
	else
	{
		return false;
	}
	
}

void start_menu() {
	int input;
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
		//tries = 6;
		//wordChosen = loadRandomWord;
		//won = fail
		//EASY
		break;
	case 2:
		//MEDIUM
		break;
	case 3: 
		//HARD
		break;
	case 'Q':
	case 'q':
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
		printMessage("o", false, false);
		printMessage("/|'\'", false, false); //BODY LEFT AND RIGHT ARM
		printMessage("", false, false);
	}
	else if (guesses[4] != NULL && tries == 5)
	{
		printMessage("o", false, false);
		printMessage("/|'\'", false, false); 
		printMessage("'\'", false, false);	//left foot
	}
	else if(guesses[5] != NULL && tries == 6)
	{
		printMessage("o", false, false);
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
	for (int i = 0; i < sizeof(guesses);i++)
	{
		if (guesses[i] != NULL)
		{
			cout << guesses[i] << " "; //edited so it doesn't mesh together
			if (i < (sizeof(guesses) -1))
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
	for (int j = 0; j < sizeof(misses); j++)
	{
		if (misses[j] != NULL)
		{
			cout << misses[j] << " ";
			if (j < (sizeof(misses)-1))
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
