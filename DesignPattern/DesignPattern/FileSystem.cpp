#include <iostream>
#include "FileSystem.h"
using namespace std;


void FileSystem::display() {
	curr->printList();
}
double FileSystem::setSize(double _size) {
	return curr->getSize();
}

void FileSystem::addEntry(entry* en, int _index) {
	curr->add(en, _index);
	fileEdit* newEdit = new fileEdit(curr, "add", _index);
	support->createUndoableEdit(newEdit);
}

void FileSystem::rmvEntry(int _index) {
	((directory*)curr)->remove(_index);
	fileEdit* newEdit = new fileEdit(curr, "remove", _index);
	support->createUndoableEdit(newEdit);
}
void FileSystem::save() {
	manager->discardAllEdits();
}

void FileSystem::undoOneStep() {
	manager->undoLast();
}
void FileSystem::undoAll() {
	manager->undoAll();
}

void FileSystem::redoOneStep() {
	manager->redoLast();
}
void FileSystem::redoAll() {
	manager->redoAll();
}

void FileSystem::help() {

	cout
		<< "\t\t\t\tpwd\t\t\t显示所有目录\t\t\t" << "\n"
		<< "\t\t\t\tls\t\t\t显示文件或目录\t\t\t" << "\n"
		<< "\t\t\t\tmkdir\t\t\t创建目录\t\t\t" << "\n"
		<< "\t\t\t\tcd\t\t\t切换目录\t\t\t" << "\n"
		<< "\t\t\t\trmdir\t\t\t删除目录及以下所有文件\t\t\t" << "\n"
		<< "\t\t\t\ttouch\t\t\t创建空文件\t\t\t" << "\n"
		<< "\t\t\t\tcat\t\t\t查看文件内容\t\t\t" << "\n"
		<< "\t\t\t\trm\t\t\t删除文件\t\t\t" << "\n"
		<< "\t\t\t\tundo\t\t\t撤销一步动作\t\t\t" << "\n"
		<< "\t\t\t\tredo\t\t\t回做一步动作\t\t\t" << "\n"
		<< "\t\t\t\tundo_all\t\t撤销到上次保存的地方\t\t\t" << "\n"
		<< "\t\t\t\tredo_all\t\t回做所有的撤销\t\t\t" << "\n"
		<< "\t\t\t\tsave\t\t\t保存当前系统(无法进行撤销)\t\t\t" << "\n"
		<< "\t\t\t\tquit\t\t\t退出系统\t\t\t" << "\n\n";
	console();
}

void FileSystem::console() {
	string cmd;
	cout << curr->getName() << " -> ";cin >> cmd;
	while (1) {
		if (cmd == "ls"  && curr->getType() == "dir") {
			this->display();
		}
		if (cmd == "mkdir" && curr->getType() == "dir") {
			string name;
			cout << "输入新文件夹名字： ";cin >> name;
			addEntry(new directory(name, (directory*)curr), index++);
			redoTmp = index;
		}
		if (cmd == "cd" && curr->getType() == "dir") {
			string name;
			cout << "输入文件或文件夹名字(输入..为进入父文件夹) : ";cin >> name;
			if (name == "..") {
				if (((directory*)curr)->getFatherDir() != NULL) {
					curr = curr->getFatherDir();
				}
			}
			else {
				entry* en = ((directory*)curr)->getEntryByName(name);
				if (en == NULL) {
					cout << "输入的文件夹或文件不存在!" << endl;
				}
				else {
					curr = en;
					save();
					index = 0;
				}
			}
		}
		if (cmd == "touch"  && curr->getType() == "dir") {
			string name;
			cout << "输入新文件名字 : ";cin >> name;
			addEntry(new file(name + ".txt", (directory*)curr), index++);
			redoTmp = index;
		}
		if (cmd == "cat" && curr->getType() == "file") {
			((file*)curr)->printContent();
		}
		if (cmd == "rm" && curr->getType() == "dir") {
			string name;
			cout << "输入要删除的文件名字 : ";cin >> name;
			name += ".txt";
			cout << ((directory*)curr)->removeEntryByNmae(name) << "\n";
		}
		if (cmd == "rmdir"&& curr->getType() == "dir") {
			string name;
			cout << "输入要删除的文件夹名字 : ";cin >> name;
			cout << ((directory*)curr)->removeEntryByNmae(name) << "\n";
		}
		if (cmd == "redo") { redoOneStep();index++; }
		if (cmd == "redo_all") { redoAll();index = redoTmp; }
		if (cmd == "undo") { undoOneStep();index--; }
		if (cmd == "undo_all") { undoAll();index = 0; }
		if (cmd == "save") { save(); }
		if (cmd == "quit") { exit(0); }
		cout << curr->getName() << " -> ";cin >> cmd;
	}
}