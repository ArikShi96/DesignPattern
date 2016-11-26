#pragma once

#include <iostream>
#include "Iobserver.h"
#include "directory.h"
#include "UndoManager.h"
using namespace std;

class FileSystem {
private:
	double size;	//ָ���ļ�ϵͳ���ڵĴ�С
	UndoManager* manager;
	directory* root;

public:
	void display();

	FileSystem() {
		size = 0;
		manager = new UndoManager();
		root = new directory("root");
	}
	void addEntry(entry* en);
	void setSize(double _size);
};