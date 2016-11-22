#include <iostream>
#include "Iobserver.h"
#include "entry.h"
using namespace std;

class FileSystem :Iobserver {
private:
	double size;	//ָ���ļ�ϵͳ���ڵĴ�С

	FileSystem(){
		size = 0;
	}
	static FileSystem* system;	//�����ֻ࣬������һ���ļ�ϵͳ;
	entry* root;
public:
	void update();
	void display();

	void setSize(double _size);
	FileSystem* getInstance();
};