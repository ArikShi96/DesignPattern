#include <iostream>
#include <vector>
#include <string>
#include "fileOperation.h"
using namespace std;
void fileOperation::undo() {
	
	//撤销这一步动作
	hasBeenDone = false;
}
void fileOperation::redo() {
	//redo这一步动作
	hasBeenDone = true;
}