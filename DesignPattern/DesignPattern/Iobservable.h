#pragma once
/*
����һ��֪ͨ�߽ӿڣ���֪ͨ�߼̳У�����֪ͨ�۲��߸ı��Լ�������
*/
#include <iostream>
#include "Iobserver.h"
#include "Object.h"
using namespace std;

class Iobservable:public Object {

public:
	virtual void addObserver(Object* observer) = 0;
	virtual void removeObserver(int index) = 0;
	virtual void notifyObserver(Object* object) = 0;
};