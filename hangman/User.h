
#pragma once 
using namespace std;
#include"Account.h"
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <vector> 

class User : public Account
{
private:
	int wins;
	int loses;
	double winPct;
	int winStreak;
	string lastPlay;


public:
	User();
	User(string n, string p, int w, int l, int wp, int ws, string lp);



	int getWins();
	void setWins(int w);
	int getLoses();
	void setLoses(int l);
	double getWinPct();
	void setWinPct(double wp);
	//cannot set win pct; should be generated by program NVM WE NEED IT 
	string getLastPlay();
	void setLastPlay(string lp);
	int getStreak();
	void setStreak(int ws);

	
	void setAllUsers(vector<User> u);

	vector<User> getUsers();

	void printHistory();
	void loadFile();
	void updateFile();


	/*TESTER FUNCTION*/
	void printUser();
};

