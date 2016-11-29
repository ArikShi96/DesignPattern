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
	fileEdit* newEdit = new fileEdit(root, "add", index++);
	edit->addEdit((UndoableEdit*)newEdit);
}

void FileSystem::rmvEntry(int _index) {

}
void FileSystem::save() {
	support->createUndoableEdit((fileEdit*)edit);
	edit = new fileEdit();
	index = 0;
}