#pragma once
/*
定义一个通知者接口，让通知者继承，用来通知观察者改变自己的数据
*/
#include <iostream>
#include <vector>
#include "Iobserver.h"
using namespace std;

class Iobservable {

public:
	virtual void addObserver(weatherObserver observer) = 0;
	virtual void removeObserver(int index) = 0;
	virtual void notifyObserver() = 0;
};

class weatherData : Iobservable {

private:
	static const int MAX_NUMBER = 10;
	double _tmp;
	double _presure;
	vector<weatherObserver> observerList;
public:
	weatherData::weatherData() {};
	void addObserver(weatherObserver observer);
	void removeObserver(int index);
	void notifyObserver();
	void setWeatherData(double tmp, double presure);
};