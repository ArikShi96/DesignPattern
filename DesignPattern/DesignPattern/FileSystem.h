#pragma once

#include <iostream>
#include "Iobserver.h"
#include "directory.h"
#include "file.h"
#include "fileEdit.h"
#include "UndoManager.h"
#include "UndoableEditSupport.h"
using namespace std;

class FileSystem {
private:
	double size;		//ָ���ļ�ϵͳ���ڵĴ�С
	directory* root;	//��Ŀ¼
	entry* curr;	//���ڵ�Ŀ¼
	UndoManager* manager;
	UndoableEditSupport* support;
	int index = 0;
	int redoTmp = 0;
public:

	FileSystem::FileSystem() {
		size = 0;
		root = new directory("root",NULL);
		curr = root;
		manager = new UndoManager();
		support = new UndoableEditSupport();
		support->addObserver((Object*)manager);
	}
	void display();
	double setSize(double _size);
	void addEntry(entry* en, int _index);
	void rmvEntry(int _index);
	void save();
	void undoOneStep();
	void undoAll();
	void redoOneStep();
	void redoAll();

	void help();

	void console();

	~FileSystem() {
		delete(root);
		delete(curr);
		delete(manager);
		delete(support);
	}
};