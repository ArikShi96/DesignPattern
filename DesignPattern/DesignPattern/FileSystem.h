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
	static FileSystem* system;
public:
	void update();
	void display();

	FileSystem* getInstance();
};