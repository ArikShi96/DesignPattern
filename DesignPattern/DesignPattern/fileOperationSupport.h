#pragma once

#include <iostream>
#include <vector>
#include "CompoundEdit.h"
#include "UndoableEditSupport.h"
#include "Iobserver.h"

class fileOperationSupport:UndoableEditSupport, Iobserver{
public:
	void update() {

	}
	void display() {

	}
};