#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "Error.h"
using namespace std;
class Matrix
{
	//friend ostream& operator<<(ostream&, const Matrix &);
	int length;
	int width;
	double** matrix;
	void Create();
	bool Overflow(double obj, double a);
	
	//void SetZero(Matrix & object);
public:
	Matrix();
	Matrix(int len, int wid);
	Matrix(int elem);
	Matrix(int len, int wid, double** matr);
	Matrix(string str);
	Matrix(const Matrix &object);
	Matrix CreateNew();
	
	static Matrix StringToMatrix(string str);
	Matrix operator+(double a);
	Matrix operator+(string str);
	Matrix operator+(Matrix matrix1);
	Matrix operator-(double a);
	Matrix operator-(string str);
	Matrix operator-(Matrix matrix1);
	Matrix operator*(double a);
	Matrix operator*(string str);
	Matrix operator*(Matrix matrix1);
	Matrix operator/(double a);
	Matrix operator/(string str);
	Matrix operator/(Matrix matrix1);
	Matrix& operator+=(double a);
	Matrix& operator+=(string str);
	Matrix& operator-=(double a);
	Matrix& operator-=(string str);
	Matrix& operator*=(double a);
	Matrix& operator*=(string str);
	Matrix& operator/=(double a);
	Matrix& operator/=(string str);
	Matrix& operator+=(Matrix matrix1);
	Matrix& operator-=(Matrix matrix1);
	Matrix& operator*=(Matrix matrix1);
	Matrix& operator/=(Matrix matrix1);
	Matrix& operator++();
	Matrix operator++(int);
	Matrix& operator--();
	Matrix operator--(int);
	bool operator>(Matrix matrix1);
	bool operator<(Matrix matrix1);
	bool operator>=(Matrix matrix1);
	bool operator<=(Matrix matrix1);
	bool operator==(Matrix matrix1);
	bool operator!=(Matrix matrix1);
	const double * operator[](int i);
	Matrix &operator=(const Matrix& object);// !!!
	//
// внешн€€ функци€ с константной ссылкой на объект
	void SetElem(int i, int j, double number);
	double GetElem(int i, int j);
	double GetConstElem(int i, int j)const;
	int GetLength();
	int GetConstLength()const;
	int GetWidth();
	int GetConstWidth()const;
	double GetSumOfElements(Matrix matrix);
	//void FloydAlgorythm();
	~Matrix();
};
ostream &operator<<(ostream & cout, const Matrix& object);
istream &operator>>(istream & cin, Matrix& object);