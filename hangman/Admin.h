using namespace std;
#include"Account.h"

class Admin : public Account
{
private:

public:
	Admin();
	Admin(string n, string p);
	bool login();
	void sort();
	void add(string word);
	void delete_word(string word);
	void sortVector(vector<string> & v);
};