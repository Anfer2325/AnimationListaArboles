#include "mangoFruit.h"

mangoFruit::mangoFruit()
{
	setWeight(0);
	this->next = nullptr;
	this->prev = nullptr;
}

mangoFruit::mangoFruit(double w,int x, int y)
{
	setWeight(w);
	this->x = x;
	this->y = y;
	this->next = nullptr;
	this->prev = nullptr;
}

void mangoFruit::setWeight(double w)
{
	this->weight = w - (0.1 * w);
}

double mangoFruit::getWeight()
{
	return this->weight;
}
