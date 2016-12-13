#pragma once
#include<iostream>
#include "Object.h"
using namespace std;

class UndoableEdit :public Object {
public:
	virtual void undo() = 0;
	virtual void redo() = 0;
	virtual bool canUndo() = 0;
	virtual bool canRedo() = 0;
	virtual string getPresentationName() = 0;
	virtual string getUndoPresentationName() = 0;
	virtual string getRedoPresentationName() = 0;
};