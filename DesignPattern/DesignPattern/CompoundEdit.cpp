#include<iostream>
#include"CompoundEdit.h"
#include<vector>
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
	return hasBeenDone;
}
void CompoundEdit::addEdit(UndoableEdit* edit) {
	undoableEditList.push_back(edit);
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

UndoableEdit* CompoundEdit::lastEdit() {
	return undoableEditList.back();
}
void CompoundEdit::end() {
	alive = false;
	return;
}