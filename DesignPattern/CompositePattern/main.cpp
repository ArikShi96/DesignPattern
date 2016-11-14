#include <iostream>
#include "directory.h"
#include "Entry.h"
#include "file.h"

using namespace std;

int main() {
	entry* f1 = new file(5, "a");
	entry* f2 = new file(4, "b");
	entry* d1 = new directory("hello");
	entry* d2 = new directory("root");
	d1->add(f1);
	d2->add(d1);
	d2->add(f2);
	d2->printList();
	cout << d2->getSize()<<endl;
}