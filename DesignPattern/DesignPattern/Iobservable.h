#pragma once
/*
����һ��֪ͨ�߽ӿڣ���֪ͨ�߼̳У�����֪ͨ�۲��߸ı��Լ�������
*/
#include <iostream>
#include "Iobserver.h"
using namespace std;

class Iobservable {

public:
	virtual void addObserver(Iobserver* observer) = 0;
	virtual void removeObserver(int index) = 0;
	virtual void notifyObserver() = 0;
};