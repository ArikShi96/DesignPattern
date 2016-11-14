#include<iostream>
#include "Iobservable.h"

void weatherData::addObserver(weatherObserver observer) {
	if (observerList.size() < MAX_NUMBER) {
		observerList.push_back(observer);
	}
}
void weatherData::removeObserver(int index) {
	if (!observerList.empty()) {
		observerList.erase(observerList.begin() + index);
	}
}
void weatherData::notifyObserver() {
	for (int i = 0; i < observerList.size();i++) {
		observerList[i].update(_tmp, _presure);
	}
}
void weatherData::setWeatherData(double tmp, double presure) {
	_tmp = tmp;
	_presure = presure;
	notifyObserver();
}