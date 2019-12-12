#pragma once 
using namespace std;
#include"Account.h"
#include<vector>
#include <iostream>
#include <fstream>
#include <string>

class Admin : public Account 
{
private:
	void sortVector(vector<string>& v);
	void importVector(string path, vector<string>& v);
	void exportVector(string path, vector<string>& v);
public:
	Admin();
	Admin(string n, string p);
	bool login();
	void sort();
	void add(string word);
	void delete_word(string word);

};