#pragma once

#include <iostream>
#include<stack>
#include "Entry.h"
#include "Iobservable.h"
#include "FileSystem.h"
using namespace std;

class file : public entry {
private:
	double size = 0;
	string name;
	string content = "";
	string tmp;
	stack<string> cache;
	directory* father;
public:
	file::file(string _name,directory* _father) {
		name = _name;
		father = _father;
	}
	string getName();
	double getSize();
	void printList();
	void add(entry* en,int index);
	void append(string str);
	entry* getFatherDir();
	string getType() { return "file"; }
	void printContent() { cout << content << endl; }

	void undo(string type,int index);
	void redo(string type,int index);
};