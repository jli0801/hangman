#include "User.h"

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

void User::setWinPct(double p)
{
	User::winPct = p;
}

string User::getLastPlay()
{
	return User::lastPlay;
}

int User::getStreak()
{
	return User::winStreak;
}

void User::setStreak(int s)
{
	User::winStreak = s;
}

void User::populateUser()
{
	//User::loadFile();
	//this is called in init()
	//so now the list is populated  
	for (int i = 0; i < this->users.size(); i++)
	{
		if (users[i].getName().compare(this->getName()) && users[i].getPassword().compare(this->getPassword()))
		{
			//if the credentials are the same 
			this->setWins(users[i].getWins());
			this->setLoses(users[i].getLoses());
			this->setStreak(users[i].getStreak());
			this->setWins(users[i].getWins());
			this->setWinPct(users[i].getWinPct());
		}
	}
}



/*

void User::setAllUsers(list<User> u)
{
	User::allUsers = u;
}

*/

void User::setAllUsers(vector<User> u)
{
	User::users = u;
}

vector<User> User::getUsers()
{
	return User::users;
}

void User::printHistory()
{
	cout << "Wins: " << this->getWins() << " ";
	cout << "Loses: " << this->getLoses() << " ";
	cout << "Winning Percentage: " << this->getWinPct() << "%" << " ";
	cout << "Last Play: " << this->getLastPlay() << " " ;
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
					if ((row.at(i) == ' ') && (row.at(i+1) != ' ') || (row.at(i) == ' ') && (row.at(i + 1) == ' ') || (row.at(i) != ' ') && (row.at(i + 1) != ' '))
					{
						index++;
					}
					if (index == 1)
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
				User addMember = User(name, password, stoi(win), stoi(loss), stoi(pct), stoi(streak), last);
				users.push_back(addMember);
				
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
	ofstream outputFile; 
	outputFile.open("UserAccountHistory.txt");
	outputFile << " Name Password Wins Losses WinPct WinStreak LastPlay" << endl;
	for(int i = 0 ; i < this->users.size(); i++)
	{
		outputFile << users[i].getName() << " " << users[i].getPassword() << "  " << to_string(users[i].getWins()) << "  " << to_string(users[i].getLoses()) << "      " << to_string(users[i].getWinPct()) << "  " << to_string(users[i].getStreak()) << "         " << users[i].getLastPlay() << endl;
	}
}

void User::printUser()
{
	for (int i = 0; i < this->users.size(); i++)
	{
		cout << users[i].getName() << " " << users[i].getPassword() << "  " << to_string(users[i].getWins()) << "  " << to_string(users[i].getLoses()) << "      " << to_string(users[i].getWinPct()) << "  " << to_string(users[i].getStreak()) << "         " << users[i].getLastPlay() << endl;
	}
}
