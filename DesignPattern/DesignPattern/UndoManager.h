#pragma once

#include<iostream>
#include"UndoableEdit.h"
#include"UndoableEditListener.h"
#include<vector>
using namespace std;

class UndoManager :UndoableEditListener{
private:
	int indexOfNextAdd = -1;
	int indexOfNextRedo = -1;
	int limit = 10;
	vector<UndoableEdit*>undoableEditList;

protected:
	void trimForLimit();
	void trimForLimit(int from, int to);
	UndoableEdit* editToBeUndone();
	UndoableEdit* editToBeRedone();

public:
	int getLimit();
	void setLimit(int _limit);
	void discardAllEdits();
	void undoTo(UndoableEdit* edit);
	void redoTo(UndoableEdit* edit);
	void undoOrRedo();
	bool canUndoOrRedo();
	void undoableEditHappened(UndoableEditEvent* event);
	void toString();
};