#include "Account.h"

//DEFAULT CONSTRUCTOR
Account::Account()
{
	name = "";
	password = "";
}
//CONSTRUCTOR 
Account::Account(string n, string p) : name(n), password(p)
{
	Account::name = n;
	Account::password = p;
}
//Login Function
//Purpose: Runs through the txt file to see if the login matches an account 
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


//GETTER FOR NAME 
string Account::getName() {
	return Account::name;
}
//GETTER FOR PASSWORD
string Account::getPassword() {
	return Account::password;
}
//SETTER FOR NAME
void Account::setName(string n)
{
	Account::name = n;
}
//SETTER FOR PASSWORD 
void Account::setPassword(string p)
{
	Account::password = p;
}
