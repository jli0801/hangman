#include "utilities.h"

bool check_guesses(char &input, int guesses[])
{
	for (int i = 0; i < sizeof(guesses); i++) {
		//guesses are chars not strings so don't use .compare
		if (input == guesses[i]) {
			cout << "Already guessed this attempt, please enter another guess";
			return false;
		}
	}
	return true;
}

bool check_letter(char &input, string &wordChosen)
{
	char cstr[wordChosen.size() + 1];
	wordChosen.copy(cstr, wordChosen.size()+1);
	cstr[str.size()] = '\0';
	for (int i = 0; i < wordChosen.size(); i++) {
		if (input == wordChosen[i]){
			return true;
			}
			return false;
	}
}

void printMessage(string message, bool printTop, bool printBottom)
{
	if (printTop)
	{
		cout << "+---------------------------------+" << endl;
		cout << "|";
	}
	else
	{
		cout << "|";
	}
	bool front = true;
	for (auto i = message.length(); i < 33; i++)
	{
		if (front)
		{
			message = " " + message;
		}
		else
		{
			message = message + " ";
		}
		front = !front;
	}
	cout << message.c_str();

	if (printBottom)
	{
		cout << "|" << endl;
		cout << "+---------------------------------+" << endl;
	}
	else
	{
		cout << "|" << endl;
	}
}

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