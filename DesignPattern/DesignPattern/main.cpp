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
	cout << "                              欢迎进入迷你文件系统" << "\n";
	cout << "                                   姓名：施峰" << "\n";
	cout << "                                   学号：1452792" << "\n";


	FileSystem* system = new FileSystem();
	//1.添加文件夹与文件
	entry* en1 = new directory("aaa");
	system->addEntry(en1);
	entry* en2 = new file("bb");
	system->addEntry(en2);
	entry* en3 = new file("cc");
	system->addEntry(en3);


}