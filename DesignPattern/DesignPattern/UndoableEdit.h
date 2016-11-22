#pragma once
#include<iostream>
using namespace std;

class UndoableEdit {
public:
	virtual void undo() {};
	virtual void redo() {};
	virtual bool canUndo() {};
	virtual bool canRedo() {};
	virtual bool isSignificant() {};
	virtual void addEdit(UndoableEdit* edit) {};
	virtual void repalceEdit(UndoableEdit* edit) {};
	virtual string getPresentationName() {};
	virtual string getUndoPresentationName() {};
	virtual string getRedoPresentationName() {};
};