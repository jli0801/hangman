using namespace std;
#include"Account.h"

class Admin : public Account
{
private:

public:
	Admin();
	Admin(string n, string p);
	void Sort();
	void Add();
	void Delete();

};