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
	virtual void update(double tmp, double presure) = 0;
	virtual void display() = 0;
};

class weatherObserver :Iobserver {
private:
	int _id;
	double _tmp;
	double _presure;
public:
	weatherObserver::weatherObserver(int id);
	void update(double tmp, double presure);
	void display();
};
