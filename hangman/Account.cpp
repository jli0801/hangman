#include "Account.h"

Account::Account()
{
	name = "";
	password = "";
}

Account::Account(string n, string p) : name(n), password(p)
{

}