#include "pch.h"
#include "Error.h"


Error::Error()
{
}

Error::Error(int a, string line) :errortype(a), errorcontent(line)
{
}

void Error::PrintError()
{
	cout << "error type " << errortype << endl;
	cout << errorcontent << endl;
}


Error::~Error()
{
}


Exeption1::Exeption1():Error(1, "can't convert line to matrix")
{
}

Exeption1::Exeption1(const Exeption1 & object)
{
	errortype = object.errortype;
	errorcontent = object.errorcontent;
}

Exeption1 & Exeption1::operator=(const Exeption1 & object)
{
	if (&object != this) {
		errortype = object.errortype;
		errorcontent = object.errorcontent;
	}
	return *this;
}


Exeption1::~Exeption1()
{
}

Exception2::Exception2():Error(2, "can't acsess matrix element on given indexes")
{
}

Exception2::Exception2(const Exception2 & object)
{
	errortype = object.errortype;
	errorcontent = object.errorcontent;
}

Exception2 & Exception2::operator=(const Exception2 & object)
{
	if (&object != this) {
		errortype = object.errortype;
		errorcontent = object.errorcontent;
	}
	return *this;
}


Exception2::~Exception2()
{
}

Exception3::Exception3():Error(3, "can't divide matrix on matrix")
{
}

Exception3::Exception3(const Exception3 & object)
{
	errortype = object.errortype;
	errorcontent = object.errorcontent;
}

Exception3 & Exception3::operator=(const Exception3 & object)
{
	if (&object != this) {
		errortype = object.errortype;
		errorcontent = object.errorcontent;
	}
	return *this;
}


Exception3::~Exception3()
{
}


Exception4::Exception4():Error(4, "can't process action because of bad matrix size")
{

}

Exception4::Exception4(const Exception4 & object)
{
	errortype = object.errortype;
	errorcontent = object.errorcontent;
}

Exception4 & Exception4::operator=(const Exception4 & object)
{
	if (&object != this) {
		errortype = object.errortype;
		errorcontent = object.errorcontent;
	}
	return *this;
}


Exception4::~Exception4()
{
}


BoxSummaaryExeption::BoxSummaaryExeption():Error(5, "Can't summarise those boxes")
{
}

BoxSummaaryExeption::BoxSummaaryExeption(const BoxSummaaryExeption & object)
{
	errortype = object.errortype;
	errorcontent = object.errorcontent;
}

BoxSummaaryExeption & BoxSummaaryExeption::operator=(const BoxSummaaryExeption & object)
{
	if (&object != this) {
		errortype = object.errortype;
		errorcontent = object.errorcontent;
	}
	return *this;
}


BoxSummaaryExeption::~BoxSummaaryExeption()
{
}


BadInputException::BadInputException(): Error(6, "Bad input format of data")
{

}

BadInputException::BadInputException(const BadInputException & object)
{
	errortype = object.errortype;
	errorcontent = object.errorcontent;
}

BadInputException & BadInputException::operator=(const BadInputException & object)
{
	if (&object != this) {
		errortype = object.errortype;
		errorcontent = object.errorcontent;
	}
	return *this;
}


BadInputException::~BadInputException()
{
}
