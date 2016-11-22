#pragma once

#include <iostream>
#include "Entry.h"
#include "Iobserver.h"
#include "FileSystem.h"
using namespace std;

class file : public entry, Iobserver {
private:
	double size;
	string name;
	vector<FileSystem*> systemList;
public:
	file::file(double _size, string _name) {
		size = _size;
		name = _name;
	}
	string getName();
	double getSize();
	void printList();
	void add(entry* en);

	void addObserver(Iobserver* observer);
	void removeObserver(int index);
	void notifyObserver();
};