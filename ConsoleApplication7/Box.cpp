#include "pch.h"
#include "Box.h"


void Box::SwapBoxes(Box * B1)
{
	swap(B1->adress, adress);
	swap(B1->volume, volume);
	swap(B1->number, number);
}

Box::Box()
{
}

Box::Box(double vol, int num, string adr)
{
	volume = vol;
	number = num;
	adress = adr;

}

double Box::GetVolume()
{
	return volume;
}

int Box::GetNumber()
{
	return number;
}

string Box::GetAdress()
{
	return adress;
}


Box::~Box()
{
}
