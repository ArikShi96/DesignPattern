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
	double size;	//ָ���ļ�ϵͳ���ڵĴ�С
	directory* root;
	fileEditManager* manager;
	fileEditSupport* support;
	fileEdit* edit;		//����ִ��
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