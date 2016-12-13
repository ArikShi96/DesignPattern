#pragma once
#include<iostream>
#include"UndoableEdit.h"

class UndoableEditEvent :public Object {
private:
	UndoableEdit* Edit;
public:
	UndoableEditEvent::UndoableEditEvent(UndoableEdit* _edit) {
		Edit = _edit;
	}
	UndoableEdit* getMyEdit() {
		return Edit;
	}
};