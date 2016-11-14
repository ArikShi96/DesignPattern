#include<iostream>
#include"Iobservable.h"
#include"Iobserver.h"

using namespace std;

int main() {
	weatherData *data = new weatherData();
	double tmp;
	double presure;
	int count; 
	while (1) {
		cout << "输入观察者的数量 : \n";
		cin >> count;
		for (int i = 0;i < count;i++) {
			weatherObserver observer(i);
			data->addObserver(observer);
		}
		cout << "输入当前的温度值与压力值 ! \n";
		cin >> tmp >> presure;
		data->setWeatherData(tmp, presure);
	}
}