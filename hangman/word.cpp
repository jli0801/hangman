#include "word.h"
#include <string.h>
#include <stdio.h>
using std::string;

word::word() {
	//default contructor 
	this->chosenWord = " ";
	setUsedWord(false);
	lettersRight = new bool[chosenWord.length()];
	for (int i = 0; i < chosenWord.length(); i++)
	{
		lettersRight[i] = false;
	}
	charGuessed = new char[1];
	charGuessed[0] = ' ';
}
word::word(string input)
{
	this->chosenWord = input;
	setUsedWord(false);
	lettersRight = new bool[chosenWord.length()];
	for (int i = 0; i < chosenWord.length(); i++)
	{
		lettersRight[i] = false;
	}
	charGuessed = new char[input.size() +1];
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
	for (int i = 0; i < chosenWord.length(); i++)
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
	//cout << "output: " << output << endl;
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

	for (int i = 0; i < sizeof(inWord.charGuessed); i++)
	{
		if (inChar == inWord.charGuessed[i])
		{
			//means they're equal
			inWord.lettersRight[i] = true;
			return true;
		}
	}
	return false;
}
