#include "FileSystem.h"
#include <iostream>
#include <vector>
#include "file.h"
#include "directory.h"
#include "fileOperation.h"
#include "CompoundEdit.h"

using namespace std;

int main()
{
	cout << "                              ��ӭ���������ļ�ϵͳ" << "\n";
	cout << "                                   ������ʩ��" << "\n";
	cout << "                                   ѧ�ţ�1452792" << "\n";


	FileSystem* system = new FileSystem();
	//1.����ļ������ļ�
	entry* en1 = new directory("aaa");
	system->addEntry(en1);
	entry* en2 = new file("bb");
	system->addEntry(en2);
	entry* en3 = new file("cc");
	system->addEntry(en3);


}