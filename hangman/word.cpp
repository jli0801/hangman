#include "word.h"
#include <string.h>
#include <stdio.h>
using std::string;

word::word() {
	//default contructor 
	this->chosenWord = " ";
	setLength(0);
	setUsedWord(false);
	lettersRight = new bool[length];
	for (int i = 0; i < length; i++)
	{
		lettersRight[i] = false;
	}
	charGuessed = new char[1];
	charGuessed[0] = ' ';
}
word::word(string input)
{
	this->chosenWord = input;
	setLength(input.length());
	setUsedWord(false);
	lettersRight = new bool[length];
	for (int i = 0; i < length; i++)
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

int word::getLength()
{
	return length;
}

string word::populateWord(string word)
{
	string output = "";

	//put the for loop here 
	for (int i = 0; i < word.length(); i++)
	{
		if (!lettersRight[i])
		{
			//false
			output += " _ ";
		}
		else
		{
			//true
			output += " ";
			output += charGuessed[i];
			output += " ";
		}
	}
	return output;
}

void word::setLength(int uLength)
{
	this->length = uLength;
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

void word::setValues(bool result, char inChar, word inWord)
{
	//set the bool array here 
	//should be used in main func 
	//letters guessed are mapped to lettersRight 
	if (result)
	{
		for (int i = 0; i < sizeof(inWord.charGuessed); i++)
		{
			if (inChar == inWord.charGuessed[i])
			{
				//means they're equal
				inWord.lettersRight[i] = true;
			}
		}
	}

}
