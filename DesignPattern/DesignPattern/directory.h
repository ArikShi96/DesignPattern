#pragma once
#include"Entry.h"
#include<vector>
#include<string>
using namespace std;

class directory :public entry {
private:
	string name;
	vector<entry*> entryList;
public:
	directory::directory(string _name) {
		name = _name;
	}
	string getName();
	int getSize();
	void add(entry* en);
	void printList();
};