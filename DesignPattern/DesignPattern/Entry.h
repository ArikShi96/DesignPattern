#pragma once
#include<iostream>

using namespace std;

class entry {

public:
	virtual string getName() = 0;
	virtual double getSize() = 0;
	virtual void add(entry* en,int index) = 0;
	virtual void printList() = 0;
	virtual entry* getFatherDir() = 0;

	virtual void undo(string type,int index) = 0;
	virtual void redo(string type,int index) = 0;
	virtual string getType() = 0;
};