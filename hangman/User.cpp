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
}

User::User(string n, string p, int w, int l, int wp, int ws, string lp) : Account(n, p)
{
	wins = w;
	loses = l;
	winPct = wp;
	winStreak = ws;
	lastPlay = lp;
	
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


list<User> User::getAllUsers()
{
	return User::allUsers;
}

void User::setAllUsers(list<User> u)
{
	User::allUsers = u;
}

void User::addUser(User &newU)
{
	User::allUsers.push_back(newU);
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
}
void User::loadFile()
{
	//create a new user for each line 
	ifstream file("UserAccountHistory.txt");
	string row;
	if (file.is_open())
	{
		while (std::getline(file, row))
		{
			//now each row is stored in row 
			//always ignore the first line
			if (!(row.compare("Name Password Wins Losses WinPct WinStreak LastPlay")))
			{
				//so if it's valuable data 
				//parse the data 
				int index = 0;
				string name, password, win, loss, pct, streak, last;
				for (int i = 0; i < row.length() - 1; i++)
				{
					if ((row.at(i) == ' ') && (row.at(i + 1) != ' '))
					{
						index++;
					}
					else if (index == 1)
					{
						name += row.at(i);
					}
					else if (index == 2)
					{
						password += row.at(i);
					}
					else if (index == 3)
					{
						win += row.at(i);
					}
					else if (index == 4)
					{
						loss += row.at(i);
					}
					else if (index == 5)
					{
						pct += row.at(i);
					}
					else if (index == 6)
					{
						streak += row.at(i);
					}
					else
					{
						last += row.at(i);
					}
				}
				User *addMember = new User(name, password, stoi(win), stoi(loss), stoi(pct), stoi(streak), last);
				this->addUser(*addMember);
			}
		}
		//able to open 
		//scan each row and each row is separated by name, password, win, losses, winpct, winstreak, last play

	}

}
void User::updateFile()
{
	//so they're updating u's 
	//change the LIST first 
	//then rewrite over the exsisting txt file with the list's info

}
