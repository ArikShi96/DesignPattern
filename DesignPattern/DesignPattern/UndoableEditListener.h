#pragma once
#include<iostream>
#include"UndoableEditEvent.h"

using namespace std;

class UndoableEditListener {
public:
	virtual void undoableEditHappened(UndoableEditEvent* event) = 0;
};