#include <iostream>
#include <vector>
#include <string>
#include "fileOperation.h"
using namespace std;
void fileOperation::undo() {
	if (canUndo()) {
		en->undo(getPresentationName());
		//撤销这一步动作
		hasBeenDone = false;
	}
}
void fileOperation::redo() {
	if (canRedo()) {
		//redo这一步动作
		en->redo(getPresentationName());
		hasBeenDone = true;
	}
}