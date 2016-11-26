#include"directory.h"
#include"file.h"
#include<vector>
using namespace std;

string directory::getName() {
	return name;
}
double directory::getSize() {
	double size = 0;
	for (int i = 0;i < entryList.size();i++) {
		size += entryList[i]->getSize();
	}
	return size;

}
void directory::add(entry* en) {
	entryList.push_back(en);
	tmp = en;
}
void directory::remove() {
	entryList.pop_back();
}
void directory::printList() {
	for (int i = 0;i < entryList.size();i++) {
		entryList[i]->printList();
	}
}

void directory::undo(string type) {
	if (type == "add") {
		remove();
	}
	if (type == "remove") {
		add(tmp);
	}
}
void directory::redo(string type) {
	if (type == "add") {
		add(tmp);
	}
	if (type == "remove") {
		remove();
	}
}