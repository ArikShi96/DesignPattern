#pragma once

#include<iostream>
#include"UndoableEdit.h"
#include<vector>
#include "Iobserver.h"
#include "UndoableEditEvent.h"
using namespace std;

class UndoManager :public Iobserver{
protected:
	int indexOfNextAdd;
	int indexOfNextRedo;
	int limit;
	vector<UndoableEdit*>undoableEditList;

	UndoableEdit* editToBeUndone();
	UndoableEdit* editToBeRedone();

public:
	UndoManager::UndoManager() {
		indexOfNextAdd = -1;
		indexOfNextRedo = -1;
		limit = 10;
	}
	UndoManager::UndoManager(int _limit) {
		 indexOfNextAdd = -1;
		 indexOfNextRedo = -1;
		 limit = _limit;
	}
	int getLimit();
	void setLimit(int _limit);
	void discardAllEdits();

	void undoAll();
	void redoAll();
	void undoLast();
	void redoLast();
	void undoOrRedo();
	bool canUndoOrRedo();
	void undoableEditHappened(UndoableEditEvent* event);
	void update(Object* object);
	void toString();
};