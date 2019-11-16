#pragma once
#include <string>
#include <algorithm>
using namespace std;
class Box
{
	double volume;
	string number;
	string adress;
	
public:
	Box();
	Box(double vol, string num, string adress);
	double GetVolume();
	string GetNumber();
	string GetAdress();
	void SwapBoxes(Box * B1);
	Box operator+(Box abox);
	~Box();
};

