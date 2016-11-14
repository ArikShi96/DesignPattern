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
