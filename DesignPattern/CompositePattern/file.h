#pragma once

#include<iostream>
#include"Entry.h"
using namespace std;

class file : public entry {
private:
	int size;
	string name;
public:
	file::file(int _size,string _name) {
		size = _size;
		name = _name;
	}
	string getName();
	int getSize();
	void printList();
	void add(entry en) { return; }
};