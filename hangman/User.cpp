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

void User::printHistory()
{
	cout << "Wins: " << wins << " ";
	cout << "Loses: " << loses << " ";
	cout << "Winning Percentage: " << winPct << "%" << " ";
	cout << "Win Streak: " << winStreak << " ";
	cout << "Last Play: " << lastPlay << " " ;
}

void User::updateWinPct()
{
	User::winPct = double (User::wins/(User::wins + User::loses)) * 100;
}