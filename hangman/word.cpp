#include "word.h"
#include <string>
using std::string;

word::word(string input)
{
	this->chosenWord = input;
	
}

string word::getWord()
{
	return this->chosenWord;
}

int word::getLength()
{
	return length;
}

void word::setUsedWord(bool input)
{

}

bool word::getUsedWord()
{
	return false;
}

void word::printWord(string word, bool top, bool bottom)
{
	string output = "";

	//put the for loop here 

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
