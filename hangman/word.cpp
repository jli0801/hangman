#include "word.h"
#include <string.h>
#include <stdio.h>
using std::string;

word::word() {
	//default contructor 
	this->chosenWord = " ";
	setUsedWord(false);
	lettersRight = new bool[1];
	lettersRight[0] = false;
	
	charGuessed = new char[1];
	charGuessed[0] = ' ';

}
word::word(string input)
{
	this->chosenWord = input;
	setUsedWord(false);
	lettersRight = new bool[(input.size() + 1)];
	for (int i = 0; i < sizeof(lettersRight); i++)
	{
		lettersRight[i] = false;
	}
	charGuessed = new char[(input.size() +1)];
	//char guessed is a char array that holds individual chars of string
	//populate the char guessed 
	for (int i = 0; i < sizeof(charGuessed); i++)
	{
		charGuessed[i] = input.at(i);
	}
}

string word::getWord()
{
	return this->chosenWord;
}

string word::populateWord()
{
	string output = "";

	//put the for loop here 
	for (int i = 0; i < sizeof(lettersRight)+1; i++)
	{
		if (!lettersRight[i])
		{
			//false
			output += "_ ";
		}
		else
		{
			//true
			output += charGuessed[i];
			output += " ";
		}
	}
	return output;
}

void word::setUsedWord(bool input)
{
	this->usedWord = input;
}

bool word::getUsedWord()
{
	return usedWord;
}

void word::printWord(string word, bool top, bool bottom)
{

	if (top)
	{
		cout << "+---------------------------------+" << endl;
		cout << "|";
	}
	else
	{
		cout << "|";
	}
	bool front = true;
	for (int i = word.length(); i < 33; i++)
	{
		if (front)
		{
			word = " " + word;
		}
		else
		{
			word = word + " ";
		}
		front = !front;
	}
	cout << word.c_str();

	if (bottom)
	{
		cout << "|" << endl;
		cout << "+---------------------------------+" << endl;
	}
	else
	{
		cout << "|" << endl;
	}
}

bool word::setValues(char inChar, word inWord)
{
	//set the bool array here 
	//should be used in main func 
	//letters guessed are mapped to lettersRight 
	bool set = false; 
	for (int i = 0; i < sizeof(inWord.charGuessed); i++)
	{
		if (inChar == inWord.charGuessed[i])
		{
			//means they're equal
			inWord.lettersRight[i] = true;
			set = true; 
		}
	}
	return set;
}

bool word::checkWholeWord(word userWord)
{
	for (int i = 0; i < sizeof(userWord.charGuessed); i++)
	{
		if (!userWord.lettersRight[i])
		{
			return false; //should automatically return false if there is a false in char guessed
		}
	}
	return true; //will return true if the for loop goes through
}
