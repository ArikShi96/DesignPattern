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
		cout << "����۲��ߵ����� : \n";
		cin >> count;
		for (int i = 0;i < count;i++) {
			weatherObserver observer(i);
			data->addObserver(observer);
		}
		cout << "���뵱ǰ���¶�ֵ��ѹ��ֵ ! \n";
		cin >> tmp >> presure;
		data->setWeatherData(tmp, presure);
	}
}