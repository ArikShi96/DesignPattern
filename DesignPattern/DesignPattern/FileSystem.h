#include <iostream>
#include "Iobserver.h"
#include "entry.h"
using namespace std;

class FileSystem :Iobserver {
private:
	double size;	//指明文件系统现在的大小

	FileSystem(){
		size = 0;
	}
	static FileSystem* system;
public:
	void update();
	void display();

	FileSystem* getInstance();
};