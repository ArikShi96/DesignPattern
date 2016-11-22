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
	static FileSystem* system;	//单例类，只允许有一个文件系统;
	entry* root;
public:
	void update();
	void display();

	void setSize(double _size);
	FileSystem* getInstance();
};