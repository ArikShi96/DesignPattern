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
		<< "\t\t\t\tpwd\t\t\t��ʾ����Ŀ¼\t\t\t" << "\n"
		<< "\t\t\t\tls\t\t\t��ʾ�ļ���Ŀ¼\t\t\t" << "\n"
		<< "\t\t\t\tmkdir\t\t\t����Ŀ¼\t\t\t" << "\n"
		<< "\t\t\t\tcd\t\t\t�л�Ŀ¼\t\t\t" << "\n"
		<< "\t\t\t\trmdir\t\t\tɾ��Ŀ¼�����������ļ�\t\t\t" << "\n"
		<< "\t\t\t\ttouch\t\t\t�������ļ�\t\t\t" << "\n"
		<< "\t\t\t\tcat\t\t\t�鿴�ļ�����\t\t\t" << "\n"
		<< "\t\t\t\trm\t\t\tɾ���ļ�\t\t\t" << "\n"
		<< "\t\t\t\tundo\t\t\t����һ������\t\t\t" << "\n"
		<< "\t\t\t\tredo\t\t\t����һ������\t\t\t" << "\n"
		<< "\t\t\t\tundo_all\t\t�������ϴα���ĵط�\t\t\t" << "\n"
		<< "\t\t\t\tredo_all\t\t�������еĳ���\t\t\t" << "\n"
		<< "\t\t\t\tsave\t\t\t���浱ǰϵͳ(�޷����г���)\t\t\t" << "\n"
		<< "\t\t\t\tquit\t\t\t�˳�ϵͳ\t\t\t" << "\n\n";
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
			cout << "�������ļ������֣� ";cin >> name;
			addEntry(new directory(name, (directory*)curr), index++);
			redoTmp = index;
		}
		if (cmd == "cd" && curr->getType() == "dir") {
			string name;
			cout << "�����ļ����ļ�������(����..Ϊ���븸�ļ���) : ";cin >> name;
			if (name == "..") {
				if (((directory*)curr)->getFatherDir() != NULL) {
					curr = curr->getFatherDir();
				}
			}
			else {
				entry* en = ((directory*)curr)->getEntryByName(name);
				if (en == NULL) {
					cout << "������ļ��л��ļ�������!" << endl;
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
			cout << "�������ļ����� : ";cin >> name;
			addEntry(new file(name + ".txt", (directory*)curr), index++);
			redoTmp = index;
		}
		if (cmd == "cat" && curr->getType() == "file") {
			((file*)curr)->printContent();
		}
		if (cmd == "rm" && curr->getType() == "dir") {
			string name;
			cout << "����Ҫɾ�����ļ����� : ";cin >> name;
			name += ".txt";
			cout << ((directory*)curr)->removeEntryByNmae(name) << "\n";
		}
		if (cmd == "rmdir"&& curr->getType() == "dir") {
			string name;
			cout << "����Ҫɾ�����ļ������� : ";cin >> name;
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