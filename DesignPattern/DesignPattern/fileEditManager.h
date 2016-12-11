#pragma once

#include "UndoManager.h"
#include <iostream>
#include "fileEdit.h"

using namespace std;

class fileEditManager :public UndoManager {
public:
	fileEditManager::fileEditManager() {
		indexOfNextAdd = -1;
		indexOfNextRedo = -1;
		limit = 10;
	}
	fileEditManager::fileEditManager(int _limit) {
		indexOfNextAdd = -1;
		indexOfNextRedo = -1;
		limit = _limit;
	}

	void undoAll() {
		for (int i = 0;i < undoableEditList.size();i++) {
			((fileEdit*)undoableEditList[i])->undo();
		}
	}

	void redoAll() {
		for (int i = 0;i < undoableEditList.size();i++) {
			((fileEdit*)undoableEditList[i])->redo();
		}
	}
};