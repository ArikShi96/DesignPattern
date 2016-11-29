#include <iostream>
#include <vector>
#include <string>
#include "fileEdit.h"
using namespace std;
void fileEdit::undo() {
	if (canUndo()) {
		en->undo(getPresentationName(),index);
		//������һ������
		hasBeenDone = false;
	}
}
void fileEdit::redo() {
	if (canRedo()) {
		//redo��һ������
		en->redo(getPresentationName(),index);
		hasBeenDone = true;
	}
}