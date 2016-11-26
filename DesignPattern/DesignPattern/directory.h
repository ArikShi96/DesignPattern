#pragma once
#include"Entry.h"
#include<vector>
#include<string>
using namespace std;

class directory :public entry {
private:
	string name;
	vector<entry*> entryList;
	entry* tmp;
public:
	directory::directory(string _name) {
		name = _name;
	}
	string getName();
	double getSize();
	void add(entry* en);
	void remove();
	void printList();

	void undo(string type);
	void redo(string type);
};