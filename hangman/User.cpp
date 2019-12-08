#include "User.h"

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