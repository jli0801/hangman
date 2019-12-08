using namespace std;
#include"Account.h"

class User : public Account
{
private:
	int wins;
	int loses;
	int winPct;
	int winStreak;
	string lastPlay;
	bool prevWin;

public:
	User();
	User(string n, string p, int w, int l, int wp, int ws, string lp, bool pw );
};