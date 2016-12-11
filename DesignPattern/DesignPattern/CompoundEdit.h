#pragma once
#include<iostream>
#include"UndoableEdit.h"
#include<vector>
using namespace std;

class CompoundEdit :public UndoableEdit {
protected:
	string UndoName;
	string RedoName;
	string presentationName;

	bool hasBeenDone;

public:
	CompoundEdit::CompoundEdit() {
		hasBeenDone = true;
	}
	CompoundEdit::CompoundEdit(string _name) {
		hasBeenDone = true;
		presentationName = _name;
	}
	void undo();
	void redo();
	bool canUndo();
	bool canRedo();
	string getPresentationName();
	string getUndoPresentationName();
	string getRedoPresentationName();
};