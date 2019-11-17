#pragma once
#include <vector>
#include <iostream>
#include "Box.h"
#include "Matrix.h"
#include "Error.h"
using namespace std;
class Deliverer
{
private:
	double capacity;
	double salary;
	double consumtion;
	double volumecarrying;
	vector <Box> CarryingNow;
	static vector <string> adres;
public:
	int time = 60 * 9;
	Deliverer();
	Deliverer(double cap, double sal, double cons, double volumecarrying);
	double GetCapasity();
	double GetSalary();
	double GetConsumption();
	double GetVolume();
	int GetNumberOfBoxes();
	
	void GroubMyBoxes();
	Box GetBox(int i);
	void AddBox(Box b);
	Box TakeBox(int i);
	void VolumeSort();
	void PrintDeliverer();
	void PrintTime();
	void SchedulePrint(vector <int> way, Matrix * map);
	void SetAdres(vector <string> adress);
	void FillBack(Deliverer * donor);
	void FillFront(Deliverer * donor);
	void InputFill();
	void Distribute(Deliverer * samovyvos);
	bool IsEmpty();
	vector <int> GetWayPoints();
	void EmptyDeliverer();
	~Deliverer();
};


