#include "User.h"
#include <sstream>
#include <iterator>
#include <vector>
//DEFAULT CONSTRUCTOR
User::User() : Account()
{
	wins = 0;
	loses = 0;
	winPct = 0;
	winStreak = 0;
	lastPlay = "";


}
//CONSTRUCTOR
User::User(string n, string p, int w, int l, double wp, int ws, string lp) : Account(n, p)
{
	wins = w;
	loses = l;
	winPct = wp;
	winStreak = ws;
	lastPlay = lp;
}
//GETTER FOR WIN
int User::getWins()
{
	return wins;
}
//SETTER FOR WIN
void User::setWins(int w)
{
	User::wins = w;
}
//GETTER FOR LOSES
int User::getLoses()
{
	return loses;
}
//SETTER FOR LOSES 
void User::setLoses(int l)
{
	User::loses = l;
}
//GETTER FOR WIN PERCENTAGE
double User::getWinPct()
{
	return winPct;
}
//SETTER FOR WIN PERCENTAGE
void User::setWinPct(double wp)
{
	User::winPct = wp;
}
//GETTER FOR LAST PLAY
string User::getLastPlay()
{
	return lastPlay;
}
//SETTER FOR LAST PLAY
void User::setLastPlay(string lp)
{
	User::lastPlay = lp;
}
//GETTER FOR WIN STREAKS
int User::getStreak()
{
	return winStreak;
}
//SETTER FOR WIN STREAKS
void User::setStreak(int s)
{
	User::winStreak = s;
}
//PRINT HISTORY
//PURPOSE: Uses cout (print stream) to display the stats of the user requested
void User::printHistory()
{
	cout << "Wins: " << this->getWins() << " ";
	cout << "Loses: " << this->getLoses() << " ";
	cout << "Win Pct: " << this->getWinPct() << "%" << " ";
	cout << "Win Streak: " << this->getStreak() << " ";
	cout << "Last Play: " << this->getLastPlay() << " " ;
}
//UPDATE WIN PCT
//Purpose: Updates the percentage after the user is done with a game
void User::updateWinPct()
{
	double total = double(this->getWins() + this->getLoses());
	
	User::winPct = double(this->getWins() / total) * 100;
}