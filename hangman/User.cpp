#include "User.h"
#include <iomanip>
#include <stdio.h>
User::User() : Account()
{
	wins = 0;
	loses = 0;
	winPct = 0;
	winStreak = 0;
	lastPlay = "";
	prevWin = false;
}

User::User(string n, string p, int w, int l, int wp, int ws, string lp, bool pw) : Account(n, p)
{
	wins = w;
	loses = l;
	winPct = wp;
	winStreak = ws;
	lastPlay = lp;
	prevWin = pw;
}

int User::getWins()
{
	return User::wins;
}

void User::setWins(int w)
{
	wins = w;
}

int User::getLoses()
{
	return User::loses;
}

void User::setLoses(int l)
{
	loses = l;
}

double User::getWinPct()
{
	return User::winPct;
}

string User::getLastPlay()
{
	return User::lastPlay;
}

bool User::getPrevWin()
{
	return User::prevWin;
}

void User::setPrevWin(bool p)
{
	prevWin = p;
}

void User::writeHistoryToFile()
{
	//rewrite to the same file name to override it 

	//HOW TO: 
	//read the entire file 
	//BUT FOR THE USER (if, else) input the new info 
	//call updateFile() from utilities 
}

void User::printHistory()
{
	cout << "Wins: " << this->getWins() << endl;
	cout << "Loses: " << this->getLoses() << endl;
	cout << "Winning Percentage: " << this->getWinPct() << "%" << endl;
	cout << "Last Play: " << this->getLastPlay() << endl;
	cout << "Previous Win? " << this->getPrevWin() << endl;
}
void User::loadFile()
{
	//create a new user for each line 
	ifstream file("UserAccountHistory.txt");
	if (file.is_open())
	{
		//able to open 
	}

}
void User::updateFile()
{
	//so they're updating u's 
	//change the LIST first 
	//then rewrite over the exsisting txt file with the list's info

}
