#pragma once
#include "Matrix.h"
#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include "Error.h"
using namespace std;
class Error
{
	
public:
	string errorcontent;
	int errortype;
	Error();
	Error(int a, string line);
	void PrintError();
	~Error();
};

class Exeption1 :
	public Error
{
public:
	Exeption1();
	Exeption1(const Exeption1& object);
	Exeption1 & operator=(const Exeption1& object);
	~Exeption1();
};
class Exception2 :
	public Error
{
public:
	Exception2();
	Exception2(const Exception2& object);
	Exception2 & operator=(const Exception2& object);
	~Exception2();
};

class Exception3 :
	public Error
{
public:
	Exception3();
	Exception3(const Exception3& object);
	Exception3 & operator=(const Exception3& object);
	~Exception3();
};

class Exception4 :
	public Error
{
public:
	Exception4();
	Exception4(const Exception4& object);
	Exception4 & operator=(const Exception4& object);
	~Exception4();
};

class BoxSummaaryExeption :
	public Error
{
public:
	BoxSummaaryExeption();
	BoxSummaaryExeption(const BoxSummaaryExeption& object);
	BoxSummaaryExeption & operator=(const BoxSummaaryExeption& object);
	~BoxSummaaryExeption();
};

class BadInputException :
	public Error
{
public:
	BadInputException();
	BadInputException(const BadInputException& object);
	BadInputException & operator=(const BadInputException& object);
	~BadInputException();
};
