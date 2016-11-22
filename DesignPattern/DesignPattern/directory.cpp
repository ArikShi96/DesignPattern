#include"directory.h"
#include"file.h"
#include<vector>
using namespace std;

string directory::getName() {
	return name;
}
int directory::getSize() {
	int size = 0;
	for (int i = 0;i < entryList.size();i++) {
		size += entryList[i]->getSize();
	}
	return size;

}
void directory::add(entry* en) {
	entryList.push_back(en);
}
void directory::printList() {
	for (int i = 0;i < entryList.size();i++) {
		entryList[i]->printList();
	}
}