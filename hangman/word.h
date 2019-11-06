#pragma once
#include <iostream>
#include <string>
using namespace std;

class word
{
private:
	string chosenWord;
	bool usedWord = false;
	bool *lettersRight;
	char *charGuessed;
	//holds the characters of the chosenWord
	
public:
	word();
	word(string input);
	string getWord();
	string populateWord();
	void setUsedWord(bool input);
	bool getUsedWord();
	void printWord(string word, bool top, bool bottom );
	bool setValues(char inChar, word inWord);
	
	//have this function run through the charGuessed

};

