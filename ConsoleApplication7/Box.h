#pragma once
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Box// a box, that we will deliver
{
	double volume;// physical characteristic
	string number;// difference characteristic
	int adress;// code of real place
	
public:
	Box();
	Box(double vol, string num, int adress);
	double GetVolume();// return volume
	string GetNumber();// return number
	int GetAdress();// return integer adress
	string GetStringAdress(vector <string> adr);// return string adress - real one
	void SwapBoxes(Box * B1);// swap their place
	Box operator+(Box abox);// to group two boxes in one with the same adresses
	~Box();
};

