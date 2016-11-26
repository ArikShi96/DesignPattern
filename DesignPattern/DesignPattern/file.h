#pragma once

#include <iostream>
#include "Entry.h"
#include "Iobservable.h"
#include "FileSystem.h"
using namespace std;

class file : public entry, Iobservable {
private:
	double size = 0;
	string name;
	string content = "";
	string tmp;
	vector<FileSystem*> systemList;
public:
	file::file(string _name) {
		name = _name;
	}
	string getName();
	double getSize();
	void printList();
	void add(entry* en);
	void append(string str);

	void addObserver(Iobserver* observer);
	void removeObserver(int index);
	void notifyObserver();

	void undo(string type);
	void redo(string type);
};