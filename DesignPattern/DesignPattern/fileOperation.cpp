#include <iostream>
#include <vector>
#include <string>
#include "fileOperation.h"
using namespace std;
void fileOperation::undo() {
	if (canUndo()) {
		en->undo(getPresentationName());
		//������һ������
		hasBeenDone = false;
	}
}
void fileOperation::redo() {
	if (canRedo()) {
		//redo��һ������
		en->redo(getPresentationName());
		hasBeenDone = true;
	}
}