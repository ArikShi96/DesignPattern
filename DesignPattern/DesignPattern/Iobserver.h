#pragma once
/*
���������࣬������Java����Ľӿ�
�ýӿ�Ϊ�۲��߽ӿ�
�ù۲�����̳�
*/
#include <iostream>
#include <vector>
using namespace std;

class Iobserver {

public:
	virtual void update() = 0;
	virtual void display() = 0;
};