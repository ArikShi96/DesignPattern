#pragma once

#include <iostream>
#include "Iobserver.h"
#include "directory.h"
#include "fileEditManager.h"
#include "fileEditSupport.h"
#include "fileEdit.h"
using namespace std;

class FileSystem {
private:
	double size;	//指明文件系统现在的大小
	directory* root;
	fileEditManager* manager;
	fileEditSupport* support;
	fileEdit* edit;		//单次执行
	int index = 0;
public:
	
	void display();

	FileSystem::FileSystem() {
		size = 0;
		root = new directory("root");
		manager = new fileEditManager();
		support = new fileEditSupport();
		edit = new fileEdit();
		support->addUndoableListener((UndoableEditListener*)manager);
	}
	void addEntry(entry* en);
	void rmvEntry(int _index);
	void save();
	void setSize(double _size);
};