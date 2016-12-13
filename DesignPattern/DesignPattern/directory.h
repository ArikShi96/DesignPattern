#pragma once
#include"Entry.h"
#include<vector>
#include<string>
#include<stack>
using namespace std;

class directory :public entry {
private:
	string name;
	directory* father;
	vector<entry*> entryList;
	stack<entry*> cache;	//��������������ʱ���汻ɾ�����ļ����ļ���
public:
	directory::directory(string _name, directory* _father) {
		name = _name;
		father = _father;
	}
	string getName();
	double getSize();
	void add(entry* en, int index);
	void remove(int index);
	void printList(int level);
	entry* getFatherDir();
	entry* getEntryByName(string name);
	string getType() { return "dir"; }

	int removeEntryByNmae(string name);

	void undo(string type, int index);
	void redo(string type, int index);
};