#include "word.h"
#include <string.h>
#include <stdio.h>
#include <array>
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
	this->lettersRight = new bool[input.length()];
	for (int i = 0; i < input.length(); i++)
	{
		this->lettersRight[i] = false;
	}
	this->charGuessed = new char[input.length()];
	//char guessed is a char array that holds individual chars of string
	//populate the char guessed 
	for (int j = 0; j < input.length() ; j++)
	{
		this->charGuessed[j] = input[j];
	}
}

string word::getWord()
{
	return this->chosenWord;
}

int word::getLength()
{
	return this->chosenWord.length();
}

string word::populateWord()
{
	string output = "";
	
	//put the for loop here 
	for (int i = 0; i < this->getLength(); i++)
	{
		
		if (!this->lettersRight[i])
		{
			//false
			output += "_ ";
		}
		else
		{
			//true
			output += this->charGuessed[i];
			output += "";
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
	return this->usedWord;
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

bool word::setValues(char inChar)
{
	//set the bool array here 
	//should be used in main func 
	//letters guessed are mapped to lettersRight 
	bool set = false; 
	for (int i = 0; i < sizeof(this->charGuessed); i++)
	{
		if (inChar == this->charGuessed[i])
		{
			//means they're equal
			this->lettersRight[i] = true;
			set = true; 
		}
	}
	return set;
}

bool word::checkWholeWord()
{
	for (int i = 0; i < sizeof(this->charGuessed); i++)
	{
		if (!this->lettersRight[i])
		{
			return false; //should automatically return false if there is a false in char guessed
		}
	}
	return true; //will return true if the for loop goes through
}
