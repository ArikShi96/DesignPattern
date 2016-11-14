#include<iostream>
#include"Iobserver.h"

weatherObserver::weatherObserver(int id) {
	_id = id;
}
void weatherObserver::update(double tmp, double presure) {
	_tmp = tmp;
	_presure = presure;
	display();
}
void weatherObserver::display() {
	cout << "the weatherObserver " << _id << " :tempreture: " << _tmp << " presure : " << _presure << "\n";
}