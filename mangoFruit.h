
#pragma once

#include <iostream>

using namespace std;

class mangoFruit
{
public:
	mangoFruit();
	mangoFruit(double,int,int);
	int x, y;
	mangoFruit* next;
	mangoFruit* prev;

	void setWeight(double);
	double getWeight();

private:
	double weight;
};
