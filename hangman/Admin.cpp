#include "Admin.h"

//default contructor
Admin::Admin() : Account()
{
	//do nothing
}

//parameterized constructor
Admin::Admin(string n, string p) : Account(n,p) 
{
	//do nothing
}

//sort given vector list alphabetically
void Admin::sortVector(vector<string>& v) {
	//using selection sort of max index
	int size = v.size(), tempIndex = 0;
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

//input string into vector list from intended file
void Admin::importVector(string path, vector<string>& v) {
	string word;
	ifstream file(path);
	if (file.is_open())
	{
		while (getline(file, word))
			v.push_back(word);
		file.close();
	}
}

//output vector list to intended file
void Admin::exportVector(string path, vector<string>& v) {
	ofstream file(path, std::ofstream::trunc);
	if (file.is_open()) {
		for (string str : v) {
			file << str << "\n";
		}
		file.close();
	}
}

// returns true if the name and password is correct
bool Admin::login() {
	if ((getName() == "uwuADMIN") && (getPassword() == "kawaiiADMIN")) {
		return true;
	}
	return false;
}

//sort word list alphabetically and rewrite it to list
void Admin::sort() {
	vector<string> v;
	string path = "wordset.txt";
	//inport list of words into vector list
	importVector(path, v);

	//sort alphabetically in ascending order
	sortVector(v);

	//write back the list back to wordset.txt
	exportVector(path, v);
}

//add word then sort list alphabetically
void Admin::add(string word) {
	vector<string> v;
	string path = "wordset.txt";

	//inport list of words into vector list
	importVector(path, v);

	//add word into the vector list
	v.push_back(word);

	//write back the list back to wordset.txt
	exportVector(path, v);
}

//delete word from list
void Admin::delete_word(string word) {
	int size = 0;
	vector<string> v;
	string path = "wordset.txt";

	//inport list of words into vector list
	importVector(path, v);
	size = v.size();

	//delete word in vector list
	for (int i = 0; i < size; i++) {
		if (word.compare(v[i]) == 0) {
			v.erase(v.begin() + i);
			break;
		}
	}	

	//write back the list back to wordset.txt
	exportVector(path, v);
}


