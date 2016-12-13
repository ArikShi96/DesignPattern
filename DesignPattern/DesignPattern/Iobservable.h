#pragma once
/*
定义一个通知者接口，让通知者继承，用来通知观察者改变自己的数据
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