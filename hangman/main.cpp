#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "utilities.h"
#include "Account.h"
#include "Admin.h"
#include "User.h"
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
bool canProceed;

//features
void start_menu(string &word, bool& canProceed);
string newWord(string& word);
void updateBoard(word user); //changing game_start to func as a update board 
void init(string&);
bool userAccess();
bool adminAccess();

int main()
{
start:
	char inputUser;
	//start of the initializer
	won = false;
	canProceed = false;
	tries = 0; //max is 6 
	guessPointer = 0; //max is 26

	//open start menu, choose a file, and pick a word from file to input into wordchosen

	while (!canProceed) {
		start_menu(wordChosen, canProceed);
	}
	init(wordChosen);
	//have to input a word from a file before populate word can be used in update board
	word usersWord = word(wordChosen);
	//cout << usersWord.getWord() << endl;
	updateBoard(usersWord);

	do{

		cout << usersWord.getWord() << endl;//TAKE THIS OUT IN THE END PLS

		cout << "\nGuess a letter/word: " << endl;
		cin >> inputUser; //could be a char or word
		system("cls");
		if (usersWord.setValues(inputUser) && (check_guesses(inputUser, guesses)))
		{
			//they found a letter or word from the chosen word
			guesses[guessPointer] = inputUser;
			guessPointer++;
			updateBoard(usersWord);

		}
		else if (!check_guesses(inputUser, guesses)) 
		{
			updateBoard(usersWord);
			printMessage("Invalid, Input is invalid/has already been guessed", true, true);
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
			printMessage("Congratulations! You Won!", true, true);
			system("pause");
			won = true;
			//if won is true and we want to prompt user if they want to play again
			if (won) {
				int userChoice = 0;
				system("cls");
				cout << "\nWould you like to return to start menu?\n1. Yes\n0. Press any other key to exit\n\nChoice: " << endl;
				cin >> userChoice;
				switch (userChoice) {
				case 1:
					system("cls");
					goto start;
					break;

				default:
					exit(0);
					break;
				}
			}
		}
	} while (!won);
	
	
	
}



void init(string& wordIn)
{
	//initialize variables 
	won = false;
	tries = 0; //max is 6 
	guessPointer = 0; //max is 26
	

	usersWord.~word();

	word usersWord = word(wordIn);

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

string newWord(string& wordIn)
{
	wordIn = loadRandomWord("wordset.txt");
	return wordIn;
}

void start_menu(string &word, bool &canProceed) {
	string inStr = "";
	int inputGame = 0;
	
	User populateUsers;
	populateUsers.loadFile();

	//populateUsers.printUser();
	
	int input;
	string userName;
	string password;
	printMessage("Hangman Game", true, false);
	printMessage("ESE224 Fall 2019", true, false);
	printMessage("Group Members:", true, false);
	printMessage("Jessica Li", false, false);
	printMessage("Dorothy Lee", false, false);
	printMessage("Lily Li", false, false);
	printMessage("Darren Li", false, true);
	printMessage("1. Start a new game", false, false);
	printMessage("2. Sign in as User", false, false);
	printMessage("3. Sign in as Admin", false, true);
	cout << "Please select a number to continue, enter 'q' to quit: ";
	cin >> input;
	switch (input) {
	case 1:
	{
		system("cls");
		printMessage("Select Difficulty:", true, false);
		printMessage("1. Easy", false, false);
		printMessage("2. Medium", false, false);
		printMessage("3. Hard", false, true);
		cout << "Please select a number to continue, enter 'q' to quit: ";
		cin >> inputGame;
		switch (inputGame)
		{
		case 1:
			system("pause");
			canProceed = true;
			wordChosen = loadRandomWord("wordset.txt");
			system("cls");
			break;
		case 2:
			//MEDIUM
		case 3:
			//HARD
		default:
			exit(0);
			break;
		}
		break;
	}
	case 2:
	{
		//LOG IN AS USER 
		canProceed = userAccess();
		if (canProceed) {
			wordChosen = loadRandomWord("wordset.txt");
		}
	}
	break;
	case 3: 
	{
		//LOG IN AS ADMIN 
		canProceed = adminAccess();
	}
	break;
	case 'Q':
	case 'q':
		cout << "\n";
		printMessage("Goodbye!", true, true);
		exit(0);	//exit the program 
		break;
	default:
		//cout << " Invalid in start menu\n";
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

bool userAccess() {
	int userMenu;
	string userName, password;
	bool exit = false;
	Account userAcc;
	User userPlaceHolder;
	cout << "Please enter your user name: " << endl;
	cin >> userName;
	cout << "Please enter your password: " << endl;
	cin >> password;

	userAcc = Account(userName, password);
	userPlaceHolder = User(userName, password, 0, 0, 0, 0, "");
	if (userAcc.Login())
	{
		cout << "You sucessfully logged in! \n";
		userPlaceHolder.populateUser();
		
		system("pause");
		string title = "Hello " + userAcc.getName();
		//have menu print again. Can choose to see stats or play game 
		
			system("cls");
			printMessage(title, true, true);
			printMessage("1. Play a Game", false, false);
			printMessage("2. Check your history", false, true);
			userPlaceHolder.printUser();

		while (!exit) {
			cout << "\nPlease select a number to continue, enter any other key to quit: ";
			cin >> userMenu;
			switch (userMenu)
			{
			case 1:
				//start menu can proceed with loaded word
				system("cls");
				return true;
				break;
			case 2:
				//print history
				userPlaceHolder.printHistory();
				break;
			default:
				//exit(0);
				exit = true;
				break;
			}
		}
		
	}
	else
	{
		cout << "Invalid Username/Password\n";
		system("pause");

	}

	system("cls");
	return false;
}

bool adminAccess() {
	string userNameAd = "",passwordAd ="", word = "";
	int adminMenu = 0;
	bool exit = false;
	Admin newAdmin;

	cout << "Please enter your user name: " << endl;
	cin >> userNameAd;
	cout << "Please enter your password: " << endl;
	cin >> passwordAd;

	newAdmin = Admin(userNameAd, passwordAd);
	if (newAdmin.login())
	{
		cout << "\nYou sucessfully logged in.\n";
		system("pause");
		//have menu print again. Can choose to manage list

		system("cls");
		printMessage("Manage Your Word List", true, true);
		printMessage("1. Sort the list alphabetically", false, false);
		printMessage("2. Add a word to the list", false, false);
		printMessage("3. Delete a word from the list", false, true);

		while (!exit) {
			cout << "\nPlease select a number to continue, enter any other key to quit: ";
			cin >> adminMenu;
			switch (adminMenu)
			{
			case 1:
				newAdmin.sort();
				break;
			case 2:
				cout << "\nPlease enter a new word to be added: ";
				cin >> word;
				newAdmin.add(word);
				break;
			case 3:
				cout << "\nPlease enter a word to be deleted: ";
				cin >> word;
				newAdmin.delete_word(word);
				break;
			default:
				//exit(0);
				system("cls");
				return false;
				break;
			}
		}
	}
	else
	{
		cout << "Invalid Username/Password\n";
		system("pause");
	}
	system("cls");
	return false;
}