#include "Admin.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

Admin::Admin() : Account()
{
}

Admin::Admin(string n, string p) : Account(n,p) 
{
}

// returns true if the name and password is correct
bool Admin::login() {
	if ((getName() == "uwuADMIN") && (getPassword() == "kawaiiADMIN")) {
		return true;
	}
	return false;
}

//sort word list alphabetically
void Admin::sort() {
	//inport list of words into vector list
	//sort alphabetically in ascending order
	//write back the list back to wordset.txt

}

//add word then sort list alphabetically
void Admin::add(string word) {
	//inport list of words into vector list
	//add word into the vector list
	//call sort vectors
	//write back the list back to wordset.txt
}

//delete word from list
void Admin::delete_word(string word) {
	//inport list of words into vector list
	//add word into the vector list
	//call sort vectors
	//write back the list back to wordset.txt

}


void sortVector(vector<string>& v) {
	//using selection sort of max index
	int size = v.size(), tempIndex;
	string min, temp;
	for (int i = 0; i < size - 1; i++) {
		min = v[i];
		for (int j = i + 1; j < size; j++) {
			if (v[j].compare(min) < 0) {
				min = v[j];
				tempIndex = j;
			}
		}
		temp = v[i];
		v[i] = min;
		v[tempIndex] = temp;
	}
}

/*
string loadRandomWord(string path)
{
	srand(time(0));
	string word;
	vector<string> v;
	ifstream file(path);
	if (file.is_open())
	{
		while (getline(file, word))
			v.push_back(word);
		word = v[rand() % v.size()];
		file.close();
	}
	return word;
}
*/