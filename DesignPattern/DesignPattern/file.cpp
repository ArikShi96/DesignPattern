#include "file.h"
#include<string>
using namespace std;

string file::getName() {
	return name;
}

double file::getSize() {
	return size;
}

void file::printList(int level) {
	for (int i = 0;i < level;i++) {
		cout << "-";
	}
	cout << name << "  " << "size: " << size << " bit\n";
}
void file::add(entry* en,int index) {
	return;
}

void file::append(string str) {
	content += str;
	cache.push_back(content);
	content_index++;
	size += str.size();  
}

void file::undo(string type,int index) {
	if (type == "append" && content_index > 0) {
		content = cache[content_index - 1];
		size = content.size();     
		content_index--;
	}
}
void file::redo(string type,int index) {
	if (type == "append") {
		if (content_index < cache.size() - 1) {
			content = cache[content_index + 1];
			size = content.size();
			content_index ++;
		}
	}
}

entry* file::getFatherDir() {
	return father;
}