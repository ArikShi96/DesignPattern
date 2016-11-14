#pragma once
#include<iostream>
#include"UndoableEdit.h"
#include<vector>
using namespace std;

class CompoundEdit :UndoableEdit {
private:
	bool inProgress;
	bool hasBeenDone = true;
	bool alive = true;
	string UndoName;
	string RedoName;
	string presentationName;
	vector<UndoableEdit*> undoableEditList;

public:
	void undo();
	void redo();
	bool canUndo();
	bool canRedo();
	bool isSignificant();
	void addEdit(UndoableEdit* edit);
	void repalceEdit(UndoableEdit* edit);
	string getPresentationName();
	string getUndoPresentationName();
	string getRedoPresentationName();

	UndoableEdit* lastEdit();
	void end();
	bool isInProgress();
};