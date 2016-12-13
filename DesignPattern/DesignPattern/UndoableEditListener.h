#pragma once
#include<iostream>
#include"UndoableEditEvent.h"
#include "Object.h"

using namespace std;

class UndoableEditListener : public Object,Iobserver{
public:
	virtual void undoableEditHappened(UndoableEditEvent* event) = 0;

};