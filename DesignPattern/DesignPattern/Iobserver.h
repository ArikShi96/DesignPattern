#pragma once
/*
���������࣬������Java����Ľӿ�
�ýӿ�Ϊ�۲��߽ӿ�
�ù۲�����̳�
*/
#include <iostream>
#include <vector>
#include "Object.h"
using namespace std;

class Iobserver:public Object {

public:
	virtual void update(Object* object) = 0;
};