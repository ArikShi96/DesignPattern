#pragma once
/*
声明纯虚类，类似于Java里面的接口
该接口为观察者接口
让观察者类继承
*/
#include <iostream>
#include <vector>
using namespace std;

class Iobserver {

public:
	virtual void update() = 0;
	virtual void display() = 0;
};