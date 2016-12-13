#pragma once
/*
声明纯虚类，类似于Java里面的接口
该接口为观察者接口
让观察者类继承
*/
#include <iostream>
#include <vector>
#include "Object.h"
using namespace std;

class Iobserver:public Object {

public:
	virtual void update(Object* object) = 0;
};