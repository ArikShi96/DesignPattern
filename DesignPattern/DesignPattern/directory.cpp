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

void directory::add(entry* en, int index) {
	entryList.insert(entryList.begin() + index, 1, en);
}
void directory::remove(int index) {
	cache.push(entryList[index]);
	entryList.erase(entryList.begin() + index);
}
void directory::printList() {
	cout << "dir : " << name << endl;
	for (int i = 0;i < entryList.size();i++) {
		entryList[i]->printList();
	}
}

void directory::undo(string type, int index) {
	entry* tmp;
	if (type == "add") {
		remove(index);
	}
	if (type == "remove") {
		if (!cache.empty()) {
			tmp = cache.top();
			cache.pop();
		}
		add(tmp, index);
	}
}
void directory::redo(string type, int index) {
	entry* tmp;
	if (type == "add") {
		if (!cache.empty()) {
			tmp = cache.top();
			cache.pop();
		}
		add(tmp, index);
	}

	if (type == "remove") {
		remove(index);
	}
}

entry* directory::getFatherDir() {
	return father;
}

entry* directory::getEntryByName(string name) {
	for (int i = 0;i < entryList.size();i++) {
		if (name == entryList[i]->getName()) {
			return entryList[i];
		}
	}
	return NULL;
}

string directory::removeEntryByNmae(string name) {
	for (int i = 0;i < entryList.size();i++) {
		if (entryList[i]->getName() == name) {
			entryList.erase(entryList.begin() + i);
			return "成功删除!!!";
		}
	}
	return "输入的文件或文件夹不存在!!!";
}