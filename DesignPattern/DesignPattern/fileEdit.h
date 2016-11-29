#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "CompoundEdit.h"
#include "Entry.h"
using namespace std;

class fileEdit : public CompoundEdit{
private:
	entry* en;
	int index = -1;
public:
	fileEdit() {

	}
	fileEdit(entry* _en,string _presentationName,int _index) {
		en = _en;
		presentationName = _presentationName;
		index = _index;
	}
	void undo();
	void redo();
};