#include "pch.h"
#include "Deliverer.h"
#include "Error.h"
#include <fstream>


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



void Deliverer::GroubMyBoxes()
{
	//vector <Box> New;
	for (int i = 0; i < CarryingNow.size() - 1; i++) {// sorting by adress of boxes
		for (int j = 0; j < CarryingNow.size() - i - 1; j++) {
			if (CarryingNow[j].GetAdress() > CarryingNow[j + 1].GetAdress()) {
				CarryingNow[j].SwapBoxes(&CarryingNow[j + 1]);
			}
		}
	}
	//string morf = CarryingNow[0].GetAdress();
	
	for (int i = 0; i < CarryingNow.size() - 1; i++) {// uniting boxes with similar adress
		if (CarryingNow[i + 1].GetAdress() == CarryingNow[i].GetAdress()) {
			CarryingNow[i] = CarryingNow[i] + CarryingNow[i + 1];
			CarryingNow.erase(CarryingNow.begin() + i + 1);
			i--;
		}	
	}
	
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
	Box took = CarryingNow[j];
	CarryingNow.erase(CarryingNow.cbegin() + j);
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

void Deliverer::PrintDeliverer(string filename)
{
	ofstream out;
	out.open(filename);
	for (int i = 0; i < CarryingNow.size(); i++) {
		out << CarryingNow[i].GetNumber() << " " << CarryingNow[i].GetStringAdress(adres) << " " << CarryingNow[i].GetVolume() << endl;
	}
}

void Deliverer::PrintTime()
{
	if (time % 60 < 10) {
		cout << time / 60 << ":0" << time % 60 << endl;
	}
	else {
		cout << time / 60 << ":" << time % 60 << endl;
	}
}

void Deliverer::SchedulePrint(vector<int> way, Matrix * map, string filename)
{
	ofstream out;
	out.open(filename, ios::app);
	vector <Box> NewCarry;
	for (int i = 0; i < CarryingNow.size(); i++) {
		int adr = way[i + 1];
		int index = 0;
		for (int j = 0; j < CarryingNow.size(); j++) {
			if (CarryingNow[j].GetAdress() == adr) {
				index = j;
				break;
			}
		}
		NewCarry.push_back(CarryingNow[index]);
		
	}
	for (int i = 0; i < way.size() - 3; i++) {
		time += 5 + round(map->GetElem(way[i], way[i + 1]) / consumtion) + rand()%11;
		out << setw(25) << left << NewCarry[i].GetNumber();
		out << setw(50) << left << NewCarry[i].GetStringAdress(adres);
		if (time % 60 < 10) {
			out << time / 60 << ":0" << time % 60 << endl;
		}
		else {
			out << time / 60 << ":" << time % 60 << endl;
		}
	}
	
	time += 5 + round(map->GetElem(way[way.size() - 3], way[way.size() - 2])) / consumtion + rand() % 11;
	out << setw(26) << left << " " << setw(49) << left << "Warehouse";
	if (time % 60 < 10) {
		out << time / 60 << ":0" << time % 60 << endl;
	}
	else {
		out << time / 60 << ":" << time % 60 << endl;
	}
}

void Deliverer::SetAdres(vector<string> adress)
{
	adres = adress;
}

void Deliverer::FillBack(Deliverer * donor)
{
	
	for(int	i = donor->CarryingNow.size() - 1; i >= 0; i--)
	{
		
		if (volumecarrying + donor->CarryingNow[i].GetVolume() < capacity) {
			Box gift = donor->TakeBox(i);
			AddBox(gift);
		}
	}
}

void Deliverer::FillFront(Deliverer * donor)
{
	for (int i = 0; i < donor->CarryingNow.size(); i++)
	{

		if (volumecarrying + donor->CarryingNow[i].GetVolume() <= capacity) {
			Box gift = donor->TakeBox(i);
			AddBox(gift);
			i--;
		}
	}
}

void Deliverer::InputFill()
{
	fstream in("input.txt");
	//cout << "Enter your number of boxes" << endl;
	int count;
	in >> count;
	//cout << "Enter your boxes" << endl;
	//cout << "volume << number << adress" << endl;
	for (int i = 0; i < count; i++) {
		string vol;
		string num;
		string adr;
		in >> vol;
		double volume = stof(vol);
		if (volume > 1000) {
			volume = 0;
		}
		getline(in, adr);
		int intadress = 0;
		for (int j = 0; j < adres.size(); j++) {
			if (adres[j] == adr) {
				intadress = j;
				break;
			}
		}
		AddBox(Box(volume, to_string(i + 1), intadress));
	}
	in.close();
	//cout << endl;
}

void Deliverer::Distribute(Deliverer * samovyvos)
{
	for (int i = 0; i < CarryingNow.size(); i++) {
		if ((CarryingNow[i].GetVolume() == 0) || (CarryingNow[i].GetAdress() == 0)) {
			Box temp = TakeBox(i);
			samovyvos->AddBox(temp);
			i--;
		}
	}
}

bool Deliverer::IsEmpty()
{
	if (CarryingNow.size() == 0) {
		return true;
	}
	return false;
}

vector<int> Deliverer::GetWayPoints()
{
	vector <int> way;
	for (int i = 0; i < CarryingNow.size(); i++) {
		way.push_back(CarryingNow[i].GetAdress());
	}
	return way;
}

void Deliverer::EmptyDeliverer()
{
	volumecarrying = 0;
	CarryingNow.erase(CarryingNow.cbegin(), CarryingNow.cend());
}




Deliverer::~Deliverer()
{
}

