#pragma once
#include<iostream>
#include"Object.h"

using namespace std;

class entry :public  Object{

public:
	virtual string getName() = 0;
	virtual double getSize() = 0;
	virtual void add(entry* en,int index) = 0;
	virtual void printList(int level) = 0;
	virtual entry* getFatherDir() = 0;

	virtual void undo(string type,int index) = 0;
	virtual void redo(string type,int index) = 0;
	virtual string getType() = 0;
};