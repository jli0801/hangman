#include "word.h"
#include <string>
using std::string;

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
	//populate the char guessed 
	strcpy(charGuessed, input.c_str());

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
	for (int i = 0; i < word.length; i++)
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
