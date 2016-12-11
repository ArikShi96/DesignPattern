#include<iostream>
#include"CompoundEdit.h"
#include<vector>
#include <string>
using namespace std;

void CompoundEdit::undo() {
	//������һ������
	hasBeenDone = false;
}
void CompoundEdit::redo() {
	//redo��һ������
	hasBeenDone = true;
}
bool CompoundEdit::canUndo() {
	return hasBeenDone;
}
bool CompoundEdit::canRedo() {
	return !hasBeenDone;
}
string CompoundEdit::getPresentationName() {
	return presentationName;
}
string CompoundEdit::getUndoPresentationName() {
	return UndoName;
}
string CompoundEdit::getRedoPresentationName() {
	return RedoName;
}
