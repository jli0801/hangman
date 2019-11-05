#pragma once
#include <iostream>
#include <string>
using namespace std;

class word
{
private:
	string chosenWord;
	int length = 0;
	bool usedWord = false;
	bool *lettersRight;
	//it's 100 but it will get reassign it 
	char *charGuessed;
	//holds the characters of the chosenWord
	
public:
	word();
	word(string input);
	string getWord();
	int getLength();
	string populateWord(string);
	void setLength(int);
	void setUsedWord(bool input);
	bool getUsedWord();
	void printWord(string word, bool top, bool bottom );
	//have this function run through the charGuessed
};

