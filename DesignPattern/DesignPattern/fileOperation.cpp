#include <iostream>
#include <vector>
#include <string>
#include "fileOperation.h"
using namespace std;
void fileOperation::undo() {
	
	//������һ������
	hasBeenDone = false;
}
void fileOperation::redo() {
	//redo��һ������
	hasBeenDone = true;
}