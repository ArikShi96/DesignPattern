#pragma once

#include "UndoableEditSupport.h"
#include "fileEditManager.h"
#include <iostream>

using namespace std;

class fileEditSupport:public UndoableEditSupport {
public:
	fileEditSupport::fileEditSupport() {}

	void postEdit() {
		for (int i = 0; i < editListenerList.size();i++) {
			((fileEditManager*)editListenerList[i])->undoableEditHappened(new UndoableEditEvent(myComEdit));
			cout << "add" << endl;
		}
	}
};