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
	bool alive;
	
	vector<UndoableEdit*> undoableEditList;

public:
	CompoundEdit::CompoundEdit() {
		hasBeenDone = true;
		alive = true;
	}
	void undo();
	void redo();
	bool canUndo();
	bool canRedo();
	void addEdit(UndoableEdit* edit);
	string getPresentationName();
	string getUndoPresentationName();
	string getRedoPresentationName();

	UndoableEdit* lastEdit();
	void end();
};