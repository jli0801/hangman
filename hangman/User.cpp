#include "User.h"
#include <sstream>
#include <iterator>
#include <vector>
User::User() : Account()
{
	wins = 0;
	loses = 0;
	winPct = 0;
	winStreak = 0;
	lastPlay = "";


}

User::User(string n, string p, int w, int l, double wp, int ws, string lp) : Account(n, p)
{
	wins = w;
	loses = l;
	winPct = wp;
	winStreak = ws;
	lastPlay = lp;
}


int User::getWins()
{
	return wins;
}

void User::setWins(int w)
{
	User::wins = w;
}

int User::getLoses()
{
	return loses;
}

void User::setLoses(int l)
{
	User::loses = l;
}

double User::getWinPct()
{
	return winPct;
}

void User::setWinPct(double wp)
{
	User::winPct = wp;
}

string User::getLastPlay()
{
	return lastPlay;
}

void User::setLastPlay(string lp)
{
	User::lastPlay = lp;
}

int User::getStreak()
{
	return winStreak;
}

void User::setStreak(int s)
{
	User::winStreak = s;
}

void User::importHistory(vector<vector<string>>& userHistory) {
	string user;
	vector<string> userVect;
	ifstream file("UserAccountHistory.txt");
	if (file.is_open())
	{
		while (getline(file, user)) {
			str_to_vector(user, userVect);
			userHistory.push_back(userVect);
		}
		
		file.close();
	}
	printHistory(userHistory);
}
void User::printHistory(vector<vector<string>>& userHistory) {
	vector<string> v;
	for (vector<string> strVect: userHistory) {
		for (string n : strVect) {

		}
		cout << endl;
	}
	
}

void User::updateHistory(vector<string> &user) {

}

void User::str_to_vector(string str, vector<string>& v) {
	// v has to be empty vector
	stringstream ss(str);
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;
	vector<string> vect(begin, end);
	v = vect;
	

	//copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
}

/*
void User::printHistory()
{
	cout << "Wins: " << this->getWins() << " ";
	cout << "Loses: " << this->getLoses() << " ";
	cout << "Winning Percentage: " << this->getWinPct() << "%" << " ";
	cout << "Last Play: " << this->getLastPlay() << " " ;
}

*/