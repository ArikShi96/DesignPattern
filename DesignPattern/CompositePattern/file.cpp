#include "file.h"
#include<string>
using namespace std;

string file::getName() {
	return name;
}

int file::getSize() {
	return size;
}

void file::printList() {
	cout << "name : " << name << ".txt " << "size : " << size << "\n";
}