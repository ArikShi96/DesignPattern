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
	cout << "                              \t\t��ӭ���������ļ�ϵͳ" << "\n";
	cout << "                                \t   ������ʩ��" << "\n";
	cout << "                                  \t ѧ�ţ�1452792" << "\n\n";

	FileSystem* system = new FileSystem();
	system->help();
}