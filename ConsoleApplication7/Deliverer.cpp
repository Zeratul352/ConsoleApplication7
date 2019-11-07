#include "pch.h"
#include "Deliverer.h"


Deliverer::Deliverer()
{
}

Deliverer::Deliverer(double cap, double sal, double cons, double volume)
{
	capacity = cap;
	salary = sal;
	consumtion = cons;
	volumecarrying = volume;
}

double Deliverer::GetCapasity()
{
	return capacity;
}

double Deliverer::GetSalary()
{
	return salary;
}

double Deliverer::GetConsumption()
{
	return consumtion;
}

double Deliverer::GetVolume()
{
	return volumecarrying;
}

int Deliverer::GetNumberOfBoxes()
{
	return CarryingNow.size();
}

Box Deliverer::GetBox(int i)
{
	return CarryingNow[i];
}

void Deliverer::AddBox(Box b)
{
	CarryingNow.push_back(b);
	volumecarrying += b.GetVolume();
}

Box Deliverer::TakeBox(int j)
{
	Box took;

	for (int i = 0; i < CarryingNow.size(); i++) {
		if (CarryingNow[i].GetNumber() == j) {
			took = CarryingNow[i];
			CarryingNow.erase(CarryingNow.begin() + i);
		}
	}
	volumecarrying -= took.GetVolume();
	return took;
}

void Deliverer::VolumeSort()
{
	int num = GetNumberOfBoxes();
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j <num - i - 1; j++) {
			if (CarryingNow[j].GetVolume() > CarryingNow[j + 1].GetVolume()) {
				CarryingNow[j].SwapBoxes(&CarryingNow[j + 1]);
			}
		}
	}
	
}

void Deliverer::PrintDeliverer()
{
	for (int i = 0; i < CarryingNow.size(); i++) {
		cout << CarryingNow[i].GetNumber() << " " << CarryingNow[i].GetAdress() << " " << CarryingNow[i].GetVolume() << endl;
	}
}




Deliverer::~Deliverer()
{
}

