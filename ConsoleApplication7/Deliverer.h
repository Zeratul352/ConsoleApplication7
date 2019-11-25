#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include "Box.h"
#include "Matrix.h"
#include "Error.h"
using namespace std;
class Deliverer
{
private:
	double capacity;
	double salary;// actually can be used to calculate, how much we have to pay for deliverer. An option for future updates
	double speed;// speed, meters per minute
	double volumecarrying;
	vector <Box> CarryingNow;
	static vector <string> adres;// array of real adresses
public:
	int time = 60 * 9;// start at 9:00
	Deliverer();
	Deliverer(double cap, double sal, double cons, double volumecarrying);
	double GetCapasity();
	double GetSalary();
	double GetSpeed();
	double GetVolume();
	int GetNumberOfBoxes();// how MANY boxes are carried now
	void GroubMyBoxes();// to proceed Genetic Search correctly; Part of our way - search algorythm
	Box GetBox(int i);
	void AddBox(Box b);
	Box TakeBox(int i);
	void VolumeSort();// sort boxes; key - volume
	void PrintDeliverer(string filename);// prints every box to "filename" file
	void PrintTime();//print in console current time
	void SchedulePrint(vector <int> way, Matrix * map, string filename);// another part of way - search algorythm; prints to file schedule of deliverer
	void SetAdres(vector <string> adress);// initialises adres vector
	void FillBack(Deliverer * donor);// replace from donor to current some boxes, from the last one to first one
	void FillFront(Deliverer * donor);// same, but from the front
	void InputFill();// read from "input.txt" and record 
	void Distribute(Deliverer * samovyvos);// send some unusual boxes to another place
	bool IsEmpty();// to use in while
	vector <int> GetWayPoints();// get points we have to visit with boxes
	void EmptyDeliverer();// throw everything out
	~Deliverer();
};


