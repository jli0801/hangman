#pragma once
#include <iostream>
#include <string>
using namespace std;

class word
{
private:
	string chosenWord;
	int length;
	bool usedWord;
	bool lettersRight[100] = { false };
	//it's 100 but it will get reassign it 
	char charGuessed[];
	//holds the characters of the chosenWord
	
public:
	word(string input);
	string getWord();
	int getLength();
	void setUsedWord(bool input);
	bool getUsedWord();
	void printWord(string word, bool top, bool bottom );
	//have this function run through the charGuessed
};

