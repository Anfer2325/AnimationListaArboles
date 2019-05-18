#pragma once
#include <iostream>
#include "mangoFruit.h"
#include <vector>
using namespace std;

class mangoTree
{
private:
	int counter;
	void increaseCounter();
	void decreaseCounter();

public:
	mangoFruit* first;
	mangoFruit* last;
	vector<mangoFruit*> mangos;
	mangoTree();
	int addMango(mangoFruit* m);
	int insertMango(mangoFruit* m, int position);
	int deleteMango(int position);
	

	int getCounter();
	
	void menu(mangoTree &,mangoTree &,bool &);
	vector<mangoFruit*> getVector();
};
