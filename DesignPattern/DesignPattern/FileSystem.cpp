#include <iostream>
#include "FileSystem.h"
using namespace std;

void FileSystem::update() {

}
void FileSystem::display() {

}

FileSystem* FileSystem::getInstance() {
	if (NULL == system) {
		system = new FileSystem();
	}
	return system;
}