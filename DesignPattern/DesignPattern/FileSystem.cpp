#include <iostream>
#include "FileSystem.h"
using namespace std;

void FileSystem::update() {

}
void FileSystem::display() {
	if (root != NULL) {
		root->printList();
	}
}

FileSystem* FileSystem::getInstance() {
	if (NULL == system) {
		system = new FileSystem();
	}
	return system;
}

void FileSystem::setSize(double _size) {
	size = _size;
}