#pragma once

#include<iostream>
#include"UndoableEdit.h"
#include"UndoableEditListener.h"
#include<vector>
using namespace std;

class UndoManager :public UndoableEditListener{
protected:
	int indexOfNextAdd;
	int indexOfNextRedo;
	int limit;
	vector<UndoableEdit*>undoableEditList;

	UndoableEdit* editToBeUndone();
	UndoableEdit* editToBeRedone();

public:
	UndoManager::UndoManager() {
		 indexOfNextAdd = 0;
		 indexOfNextRedo = 0;
		 limit = 10;
	}
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