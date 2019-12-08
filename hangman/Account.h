using namespace std;
#include<string>
#include<fstream>
#include<iostream>

class Account {
private:
	string name;
	string password;
public:
	Account();
	Account(string n, string p);
	bool Login();
	string getName();
	string getPassword();
};