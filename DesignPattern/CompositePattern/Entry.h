#pragma once
#include<iostream>

using namespace std;

class entry {

public:
	virtual string getName() { return NULL; };
	virtual int getSize() { return -1; };
	virtual void add(entry* en) {};
	virtual void printList() {};
};