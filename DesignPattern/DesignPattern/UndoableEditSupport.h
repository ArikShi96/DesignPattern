#pragma once
#include <iostream>
#include <vector>
#include "CompoundEdit.h"
#include "Iobserver.h"

using namespace std;

class UndoableEditSupport :public Iobservable {
protected:
	vector<Iobserver*> editListenerList;
public:
	UndoableEditSupport::UndoableEditSupport() {}

	vector<Iobserver*> getEditListenerList() { return editListenerList; }

	void addObserver(Object* observer) {
		editListenerList.push_back((Iobserver*)observer);
	}
	void removeObserver(int index) {
		editListenerList.erase(editListenerList.begin() + index);
	}

	void notifyObserver(Object* object) {
		for (int i = 0; i < editListenerList.size();i++) {
			editListenerList[i]->update(object);
		}
	}
};