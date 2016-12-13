#include<iostream>
#include "UndoManager.h"
#include<vector>
#include<string>
using namespace std;

UndoableEdit* UndoManager::editToBeUndone() {
	if (indexOfNextAdd != -1) {
		return undoableEditList[indexOfNextAdd];
	}
	return NULL;
}
UndoableEdit* UndoManager::editToBeRedone() {
	if (indexOfNextRedo != -1) {
		return undoableEditList[indexOfNextAdd + 1];
	}
	return NULL;
}

int UndoManager::getLimit() {
	return limit;
}
void UndoManager::setLimit(int _limit) {
	limit = _limit;
}
void UndoManager::discardAllEdits() {
	undoableEditList.clear();
	indexOfNextAdd = -1;
	indexOfNextRedo = -1;
}
void UndoManager::undoAll() {
	while (indexOfNextAdd > -1) {
		undoableEditList[indexOfNextAdd--]->undo();
	}
}
void UndoManager::redoAll() {
	if (indexOfNextAdd == indexOfNextRedo) {
		return;
	}
	for (int i = 0;i < undoableEditList.size();i++) {
		undoableEditList[i]->redo();
		indexOfNextAdd++;
	}
}
void UndoManager::undoOrRedo() {
	if (undoableEditList[indexOfNextAdd]->canUndo()) {
		undoableEditList[indexOfNextAdd]->undo();
		indexOfNextAdd--;
	}
	if (undoableEditList[indexOfNextRedo]->canRedo()) {
		undoableEditList[indexOfNextRedo]->redo();
		indexOfNextAdd++;
	}
}
bool UndoManager::canUndoOrRedo() {
	return !undoableEditList.empty();
}

void UndoManager::update(Object* object) {
	undoableEditHappened(new UndoableEditEvent((UndoableEdit*)object));
}

void UndoManager::undoableEditHappened(UndoableEditEvent* event) {
	if (indexOfNextAdd > limit)return;
	//undo之后再执行新的动作，会将undo到的动作之后的所有动作覆盖掉,也就是不能再redo了;
	int size = undoableEditList.size();
	if (indexOfNextAdd != size - 1) {
		int count = size - indexOfNextAdd - 1;
		while (count) {
			undoableEditList.pop_back();
			count--;
		}
	}
	undoableEditList.push_back(event->getMyEdit());
	indexOfNextAdd++;
	indexOfNextRedo = indexOfNextAdd;
}

void UndoManager::undoLast() {
	UndoableEdit* edit = editToBeUndone();
	if (edit != NULL) {
		if (edit->canUndo()) {
			edit->undo();
			indexOfNextAdd--;
		}
	}
}
void UndoManager::redoLast() {
	if (indexOfNextAdd == indexOfNextRedo) {
		return;
	}
	UndoableEdit* edit = editToBeRedone();
	if (edit != NULL) {
		if (edit->canRedo()) {
			edit->redo();
			indexOfNextAdd++;
		}
	}
}

void UndoManager::toString() {
	for (int i = 0;i < undoableEditList.size();i++) {
		cout << undoableEditList[i]->getPresentationName() << "\n";
	}
}