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
	cout << "  name : " << name << "\t" << "size : " << size << "\n";
}
void file::add(entry* en,int index) {
	return;
}

void file::append(string str) {
	cache.push(content);
	content += str;
	size += str.size();
}

void file::undo(string type,int index) {
	if (type == "append") {
		content = cache.top();
		size = content.size();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
		cache.pop();
	}
}
void file::redo(string type,int index) {
	
}

entry* file::getFatherDir() {
	return father;
}