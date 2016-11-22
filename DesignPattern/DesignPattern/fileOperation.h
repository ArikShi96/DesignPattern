#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "CompoundEdit.h"
#include "Entry.h"
using namespace std;

class fileOperation: CompoundEdit{
private:
	entry* en;
public:
	void undo();
	void redo();
};