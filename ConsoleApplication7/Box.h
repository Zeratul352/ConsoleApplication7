#pragma once
#include <string>
#include <algorithm>
using namespace std;
class Box
{
	double volume;
	int number;
	string adress;
	
public:
	Box();
	Box(double vol, int num, string adress);
	double GetVolume();
	int GetNumber();
	string GetAdress();
	void SwapBoxes(Box * B1);

	~Box();
};

