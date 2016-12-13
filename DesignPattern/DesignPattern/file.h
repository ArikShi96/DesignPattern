#pragma once

#include <iostream>
#include<vector>
#include "Entry.h"
#include "Iobservable.h"
#include "FileSystem.h"
using namespace std;

class file : public entry {
private:
	int content_index = 0;
	double size = 0;
	string name;
	string content = "";
	string tmp;
	vector<string> cache;
	directory* father;
public:
	file::file(string _name,directory* _father) {
		name = _name;
		father = _father;
		cache.push_back(content);
	}
	string getName();
	double getSize();
	void printList(int level);
	void add(entry* en,int index);
	void append(string str);
	entry* getFatherDir();
	string getType() { return "file"; }
	void printContent() { cout << content << endl; }

	void undo(string type,int index);
	void redo(string type,int index);
};