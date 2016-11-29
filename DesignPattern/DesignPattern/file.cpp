#include "file.h"
#include<string>
using namespace std;

string file::getName() {
	return name;
}

double file::getSize() {
	return size;
}

void file::printList() {
	cout << "name : " << name << "\t" << "size : " << size <<"\tcontent: "<<content<< "\n";
}
void file::add(entry* en) {
	return;
}

void file::addObserver(Iobserver* observer) {
	systemList.push_back((FileSystem*)observer);
}
void file::removeObserver(int index) {
	systemList.erase(systemList.begin() + index);
}
void file::notifyObserver() {
	for (int i = 0;i < systemList.size();i++) {
	
	}
}

void file::append(string str) {
	content += str;
	tmp = str;
	size += str.length();
}

void file::undo(string type) {
	content = content.substr(0, content.size() - tmp.size());
}
void file::redo(string type) {
	append(tmp);
}
