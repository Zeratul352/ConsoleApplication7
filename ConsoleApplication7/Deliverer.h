#pragma once
#include <vector>
#include <iostream>
#include "Box.h"
using namespace std;
class Deliverer
{
private:
	double capacity;
	double salary;
	double consumtion;
	double volumecarrying;
	vector <Box> CarryingNow;
public:
	Deliverer();
	Deliverer(double cap, double sal, double cons, double volumecarrying);
	double GetCapasity();
	double GetSalary();
	double GetConsumption();
	double GetVolume();
	int GetNumberOfBoxes();
	Box GetBox(int i);
	void AddBox(Box b);
	Box TakeBox(int i);
	void VolumeSort();
	void PrintDeliverer();
	~Deliverer();
};


