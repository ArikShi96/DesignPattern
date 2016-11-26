#include <iostream>
#include "FileSystem.h"
using namespace std;

void FileSystem::display() {
	if (root != NULL) {
		root->printList();
	}
}

void FileSystem::setSize(double _size) {
	size = _size;
}

void FileSystem::addEntry(entry* en) {
	root->add(en);
}