#pragma once
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Box
{
	double volume;
	string number;
	int adress;
	
public:
	Box();
	Box(double vol, string num, int adress);
	double GetVolume();
	string GetNumber();
	int GetAdress();
	string GetStringAdress(vector <string> adr);
	void SwapBoxes(Box * B1);
	Box operator+(Box abox);
	~Box();
};

