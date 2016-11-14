#include<iostream>
#include "UndoManager.h"
#include<vector>
#include<string>
using namespace std;

void UndoManager::trimForLimit() {

}
void UndoManager::trimForLimit(int from, int to) {

}
UndoableEdit* UndoManager::editToBeUndone() {
	return undoableEditList[indexOfNextAdd - 1];
}
UndoableEdit* UndoManager::editToBeRedone() {
	return undoableEditList[indexOfNextAdd ];
}

int UndoManager::getLimit() {
	return limit;
}
int UndoManager::setLimit(int _limit) {
	limit = _limit;
}
void UndoManager::discardAllEdits() {
	undoableEditList.clear();
}
void UndoManager::undoTo(UndoableEdit* edit) {
	edit->undo();
}
void UndoManager::redoTo(UndoableEdit* edit) {
	edit->redo();
}
void UndoManager::undoOrRedo() {
	indexOfNextAdd--;
}
bool UndoManager::canUndoOrRedo() {

}
void UndoManager::undoableEditHappened(UndoableEditEvent* event) {
	undoableEditList.push_back(event->getMyEdit());
	indexOfNextAdd ++;
}
string UndoManager::toString() {
	for (int i = 0;i < undoableEditList.size();i++) {
		cout << undoableEditList[i]->getPresentationName() << "\n";
	}
}