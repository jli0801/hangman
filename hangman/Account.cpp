#include "Account.h"

Account::Account()
{
	name = "";
	password = "";
}

Account::Account(string n, string p) : name(n), password(p)
{
	Account::name = n;
	Account::password = p;
}

bool Account::Login() {
	int i = 0;
	string word = "";
	ifstream file("UserAccountHistory.txt");
	if (file.is_open())
	{
		while (!file.eof()) {
			file >> word;
				if ((word.compare(name)==0)&&(i%7 == 0)) {
					//username is identified in file
					file >> word;
					//checks next string to check password
					if (word.compare(password)==0)
						return true;
				}
				i++;
		}
		file.close();
	}
	return false;
}



string Account::getName() {
	return Account::name;
}

string Account::getPassword() {
	return Account::password;
}

void Account::setName(string n)
{
	Account::name = n;
}

void Account::setPassword(string p)
{
	Account::password = p;
}
