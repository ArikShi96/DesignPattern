#include "FileSystem.h"
#include <iostream>
#include <vector>
#include "file.h"
#include "directory.h"
#include "CompoundEdit.h"
#include "UndoableEditSupport.h"

using namespace std;

int main()
{
	cout << "                              \t\t欢迎进入迷你文件系统" << "\n";
	cout << "                                \t   姓名：施峰" << "\n";
	cout << "                                  \t 学号：1452792" << "\n\n";

	FileSystem* system = new FileSystem();
	system->help();
}