#pragma once
#include<iostream>
#include"UndoableEditEvent.h"

using namespace std;

class UndoableEditListener {
public:
	void undoableEditHappened(UndoableEditEvent* event) {};
};