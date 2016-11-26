#pragma once
#include <iostream>
#include <vector>
#include "CompoundEdit.h"
#include "UndoableEditListener.h"

using namespace std;

class UndoableEditSupport {
protected:
	UndoableEdit* myComEdit;
	vector<UndoableEditListener*> editListenerList;
public:
	UndoableEditSupport::UndoableEditSupport() {
	}

	void addUndoableListener(UndoableEditListener* listener) { editListenerList.push_back(listener); }

	void removeUndoableListener(UndoableEditListener* listener) {  };

	vector<UndoableEditListener*> getEditListenerList() { return editListenerList; }

	void createUndoableEdit(UndoableEdit* edit) {
		 myComEdit = edit;
		 postEdit();
	}

	void postEdit() {
		for (int i = 0; i < editListenerList.size();i++) {
			editListenerList[i]->undoableEditHappened(new UndoableEditEvent(myComEdit));
		}
	}
};