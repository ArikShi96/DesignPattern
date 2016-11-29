#include <iostream>
#include <vector>
#include <string>
#include "fileEdit.h"
using namespace std;
void fileEdit::undo() {
	if (canUndo()) {
		en->undo(getPresentationName(),index);
		//撤销这一步动作
		hasBeenDone = false;
	}
}
void fileEdit::redo() {
	if (canRedo()) {
		//redo这一步动作
		en->redo(getPresentationName(),index);
		hasBeenDone = true;
	}
}