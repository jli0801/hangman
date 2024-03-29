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
int index;
bool won;
bool canProceed;
//MAKE A GLOBAL USER THAT WE CAN OVERRIDE WHEN THE USER LOGS IN 

vector<User> users;

//features
void start_menu(string &word, bool& canProceed);
string newWord(string& word);
void updateBoard(word user); //changing game_start to func as a update board 
void init(string&);
bool userAccess();
bool adminAccess();

void loadFile();
void printUser();
void updateFile();
void findUser(string username, string password);

//MAIN FUNCTION
int main()
{
start:
	loadFile();
	vector<string> status;
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
	updateBoard(usersWord);

	do{



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
			users[index].setWins(users[index].getWins()+1);
			users[index].updateWinPct();
			users[index].setStreak(users[index].getStreak() + 1);
			users[index].setLastPlay(usersWord.getWord());
			updateFile();
			users.clear();
			loadFile();
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


//INIT FUNCTION
//Purpose: Clears the variables, arrays, vector to reset the game.
void init(string& wordIn)
{
	//initialize variables 
	won = false;
	tries = 0; //max is 6 
	guessPointer = 0; //max is 26
	

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

//NEW WORD
//Purpose: Loads a new word 
string newWord(string& wordIn)
{
	wordIn = loadRandomWord("wordset.txt");
	return wordIn;
}

//START MENU
//Purpose: Generates the start menu
void start_menu(string &word, bool &canProceed) {
	string inStr = "";
	int inputGame = 0;
	
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
			
			system("pause");
			canProceed = true;
			wordChosen = loadRandomWord("wordset_intermediate.txt");
			system("cls");
			break;
			
		case 3:
			//HARD
			
			system("pause");
			canProceed = true;
			wordChosen = loadRandomWord("wordset_advanced.txt");
			system("cls");
			break;
			
		default:
			exit(0);
			break;
		}
		break;
	}
	case 2:
	{
		//LOG IN AS USER 
		/*
		FOR EXTRA CREDIT: PUT IN THE EASY, MEDIUM AND HARD 
		*/
		canProceed = userAccess();
		if (canProceed) {
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

				system("pause");
				canProceed = true;
				wordChosen = loadRandomWord("wordset_intermediate.txt");
				system("cls");
				break;

			case 3:
				//HARD

				system("pause");
				canProceed = true;
				wordChosen = loadRandomWord("wordset_advanced.txt");
				system("cls");
				break;

			default:
				exit(0);
				break;
			}
			break;
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

//UPDATE BOARD
//Purpose: Updates the board with the hangman if the input is correct/incorrect
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
		printMessage("     YOU LOSE:(     ", true, true);
		users[index].setLoses(users[index].getLoses() + 1);
		users[index].updateWinPct();
		users[index].setStreak(0);
		users[index].setLastPlay(usersWord.getWord());
		updateFile();
		users.clear();
		loadFile();
		cout << "\n";
		exit(0);
	}

}

//USER ACCESS
//Purpose: Tests whether the user can login
bool userAccess() {
	int userMenu;
	string userName, password;
	bool exit = false;
	Account userAcc;
	//User userPlaceHolder;
	cout << "Please enter your user name: " << endl;
	cin >> userName;
	cout << "Please enter your password: " << endl;
	cin >> password;

	userAcc = Account(userName, password);

	if (userAcc.Login())
	{
		cout << "You sucessfully logged in! \n";

		system("pause");
		findUser(userName, password);

			system("cls");
			printMessage("1. Play a Game", false, false);
			printMessage("2. Check your history", false, true);

		while (!exit) {
			cout << "\nPlease select 1 to play, enter any other number to return to menu: ";
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
				
				users[index].printHistory();
				break;
			default:
			
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

//ADMIN ACCESS
//Purpose: Test whether the admin can log in or not 
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


//LOAD FILE
//Purpose: Takes the txt file and converts it into a vector of Users
void loadFile()
{
	string word = "";
	string name, password, last, heading;
	int win, loss, streak;
	double pct;
	int counter = 1;
	ifstream file("UserAccountHistory.txt");
	if (file.is_open())
	{
		for (int i = 0; i < 7; i++)
		{
			file >> heading;
		}

		while (!file.eof())
		{
			//we need to skip the first line

			while (file >> name >> password >> win >> loss >> pct >> streak >> last)
			{
				if ((name.compare("Name") != 0) && (password.compare("Password") != 0))
				{
					users.push_back(User(name, password, win, loss, pct, streak, last));

				}

			}
		}
	}
	file.close();

}

//UPDATE File
//Purpose: Takes the vector of users and prints it back to the UserAccountHistory 
void updateFile()
{
	//so they're updating u's 
	//change the LIST first 
	//then rewrite over the exsisting txt file with the list's info
	ofstream outputFile; 
	outputFile.open("UserAccountHistory.txt");

	outputFile << "Name Password Wins Losses WinPct WinStreak LastPlay" << endl;
	for(int i = 0 ; i < users.size(); i++)
	{
		outputFile << users[i].getName() << " " << users[i].getPassword() << " " << to_string(users[i].getWins()) << "  " << to_string(users[i].getLoses()) << "     " << to_string(users[i].getWinPct()) << "  " << to_string(users[i].getStreak()) << "     " << users[i].getLastPlay() << endl;
	}
	outputFile.close();
}

//PRINT USER
//Purpose: Used for testing purposes to see the insides of vector<User> 
void printUser()
{
	for (int i = 0; i < users.size(); i++)
	{
		cout << users[i].getName() << " " << users[i].getPassword() << "  " << to_string(users[i].getWins()) << "  " << to_string(users[i].getLoses()) << "      " << to_string(users[i].getWinPct()) << "  " << to_string(users[i].getStreak()) << "         " << users[i].getLastPlay() << endl;
	}
}

//findUser
//Purpose: Finds the index in the vector of the User 
void findUser(string username, string password)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (((users[i].getName()).compare(username) == 0) && ((users[i].getPassword()).compare(password) == 0))
		{
			index = i;
		}
	}
}

