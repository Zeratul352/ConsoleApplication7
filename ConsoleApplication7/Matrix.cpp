#include "pch.h"
#include "Matrix.h"

Matrix Zero = Matrix(0);

void Matrix::Create()
{
	matrix = new double*[length];
	for (int i = 0; i < length; i++) {
		matrix[i] = new double [width];
	}
	//cout << "Matrix.ctor(" << length << ", " << width << ")" << endl;
}

bool Matrix::Overflow(double obj, double a)
{
	
	if ((obj >= 0) && (a >= 0)) {
		if (obj + a >= 0) {
			return true;
		}
	}
	
	else if ((obj >= 0) && (a < 0)) {
		if (obj >= -a) {
			return true;
		}
		else {
			if (obj + a < 0) {
				return true;
			}
		}
	}
	else if ((obj < 0) && (a >= 0)) {
		if (-obj >= a) {
			return true;
		}
		else {
			if (-obj - a < 0) {
				return true;
			}
		}
	}
	else if ((obj < 0) && (a < 0)) {
		if (obj + a < 0) {
			return true;
		}
	}
	return false;
	/*if ((obj >= 0) && (obj + a >= 0)) {
		return true;
	}
	else if ((obj <= 0) && (obj + a <= 0)) {
		return true;
	}
	else {
		return false;
	}*/
}

Matrix Matrix::StringToMatrix(string str)
{
	const char *line = str.c_str();
	char elements[] = "[-1234567890,;.]";
	char numbers[] = "1234567890";
	int koma = 0;
	int point = 0;
	
		if ((line[0] == '[') && (line[strlen(line) - 1] == ']')) {

			for (int i = 1; i < strlen(line); i++) {
				char m = line[i];
				if (line[i] == ',') {
					if ((line[i - 1] < '0') || (line[i - 1] > '9')) {
						throw Exeption1();
						return Zero;
					}
				}
				else if (line[i] == ';') {
					if ((line[i - 1] < '0') || (line[i - 1] > '9')) {
						throw Exeption1();
						return Zero;
					}
					point++;
				}
				/*else {
					//cout << m << "\n";
					if (!strcspn(elements, &m)) {
						cout << m << "\n";
						throw Exeption1();
						return Zero;
					}
				}*/
			}
		}
	
	int m = 0;
	while ((line[m] != ';') && (line[m] != ']')) {
		if (line[m] == ',') {
			koma++;
		}
		m++;
	}
	int komas = 0;
	for (int i = 0; i < strlen(line); i++) {
		
		if (line[i] == ',') {
			komas++;
		}
		else if ((line[i] == ';') || (line[i] == ']')) {
			if (koma != komas) {
				throw Exeption1();
				//return Zero;
			}
			else {
				komas = 0;
			}
		}

	}
	int wid = koma + 1;
	int len = point + 1;
	int i1 = 0;
	int j1 = 0;
	Matrix matr = Matrix(len, wid);
	char charline[20000];
	for (int i = 0; i < strlen(line); i++) {
		charline[i] = line[i];
	}
	charline[0] = ' ';
	while (charline[strlen(line) - 1] != ' ') {
		double a = atof(charline);
		matr.SetElem(i1, j1, a);
		int i = 1;
		while ((charline[i] != ';') && (charline[i] != ',') && (charline[i] != ']')) {
			charline[i] = ' ';
			i++;
		}
		if ((charline[i] == ';')) {
			i1++;
			j1 = 0;
		}
		else if (charline[i] == ',') {
			j1++;
		}
		charline[i] = ' ';
	}
	/*for (int i = 1; i < line.size; i++) {// массив с индексами , и ; первое вхождение числа
		char num[20];
		int j = 0;
		double a = atof(num);
		if (a != 0.0) {
			matr.SetElem(i1, j1, a);
			if (koma != 0) {
				i = line.find(',');
				j1++;
				koma--;
			}
			if (point != 0) {
				i = line.find(';')
			}
		}
		else {
			return Zero;
		}
		

		/*if ((line[i] != '[') && (line[i] != ']') && (line[i] != ';') && (line[i] != ',')) {
			num[j] = line[i];
			j++;
		}
		else if(line[i] == ','){
			double a = atof(num);
		}*/
	return matr;
}

	
	 


/*void Matrix::SetZero(Matrix & object)
{
	Matrix matr = Zero;

}*/

Matrix::Matrix()
{
	//cout << "constructor" << endl;
}

Matrix::Matrix(int len, int wid)
{
	
	length = len;
	width = wid;
	Create();
	
}

Matrix::Matrix(int elem)
{
	//cout << "constructor" << endl;
	length = 1;
	width = 1;
	Create();
	matrix[0][0] = elem;
}

Matrix::Matrix(int len, int wid, double ** matr)
{
	//cout << "constructor" << endl;
	length = len;
	width = wid;
	Create();
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = matr[i][j];
		}
	}
}

Matrix::Matrix(string str)
{
	const char *line = str.c_str();
	*this = StringToMatrix(line);
}

Matrix::Matrix(const Matrix & object)
{
	//cout << "copy constructor" << endl;
	length = object.GetConstLength();
	width = object.GetConstWidth();
	Create();
	//Matrix matrix = Matrix(len, wid);
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = object.GetConstElem(i, j);
		}
	}

}

Matrix Matrix::CreateNew()
{
	cout << "Input length << width of your matrix" << endl;
	int len, wid;
	cin >> len >> wid;
	Matrix matrix = Matrix(len, wid);
	cout << "now input elements of your matrix" << endl;
	cin >> matrix;
	return matrix;
}

/*void Matrix::FloydAlgorythm()
{
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][j] = 10000.0;
			}
		}
	}
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			for (int k = 0; k < length; k++) {
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}
	
}*/

Matrix Matrix::operator+(double a)
{
	
		if (this->width != this->length) {
			throw Exception4();
		}
	
	
	Matrix matr = Matrix(this->length, this->width, this->matrix);
	for (int i = 0; i < this->length; i++) {
		if (Overflow(matrix[i][i], a)){
			matr.SetElem(i, i, GetElem(i, i) + a);
		}
		else {
			return Zero;
		}
	}
	return matr;
}
Matrix Matrix::operator+(string str)
{
	const char *line = str.c_str();
	double a = atof(line);
	if (a != 0) {
		Matrix A = *this;
		return A + a;
	}
	
	Matrix A = StringToMatrix(str);
	
	return *this + A;
}
Matrix Matrix::operator-(double a)
{
	
		if (this->width != this->length) {
			throw Exception4();
		}
	
	Matrix matr = Matrix(this->length, this->width, this->matrix);
	for (int i = 0; i < this->length; i++) {
		if (Overflow(matrix[i][i], -a)) {
			matr.SetElem(i, i, GetElem(i, i) - a);
		}
		else {
			return Zero;
		}
	}
	return matr;
}
Matrix Matrix::operator-(string str)
{
	const char *line = str.c_str();
	double a = atof(line);
	if (a != 0) {
		return *this - a;
	}

	Matrix A = StringToMatrix(str);

	return *this - A;
}
Matrix Matrix::operator*(double a)
{
	
	Matrix matr = Matrix(this->length, this->width, this->matrix);
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < width; j++) {
			matr.SetElem(i, j, GetElem(i, j) * a);
		}
		
	}
	return matr;
}

Matrix Matrix::operator*(string str)
{
	const char *line = str.c_str();
	double a = atof(line);
	if (a != 0) {
		return *this * a;
	} 

	Matrix A = StringToMatrix(str);

	return *this * A;
}

Matrix Matrix::operator/(double a)
{
	/*if (a == 0) {
		double ** mat = new double*[1];
		for (int i = 0; i < 1; i++) {
			mat[i] = new double[1];
		}
		mat[0][0] = 0;
		Matrix matr = Matrix(1, 1, mat);
		return matr;
	}*/
	
		if (a == 0) {
			throw Exception3();
		}
	
	Matrix matr = Matrix(this->length, this->width, this->matrix);
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < width; j++) {
			matr.SetElem(i, j, GetElem(i, j) / a);
		}
	}
	return matr;
}

Matrix Matrix::operator/(string str)
{
	const char *line = str.c_str();
	double a = atof(line);
	if (a != 0) {
		return *this / a;
	}

	Matrix A = StringToMatrix(str);

	return *this / A;
}

Matrix Matrix::operator+(Matrix matrix1)
{
	
		if ((this->length != matrix1.GetLength()) || (this->width != matrix1.GetWidth())) {
			throw Exception4();
		}
	
	Matrix matr = Matrix(this->length, this->width, this->matrix);
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < this->width; j++) {
			if (Overflow(matrix[i][j], matrix1.GetElem(i, j))) {
				matr.SetElem(i, j, GetElem(i, j) + matrix1.GetElem(i, j));
			}
			else {
				return Zero;
			}
			
		}
	}
	return matr;
}
Matrix Matrix::operator-(Matrix matrix1)
{
	if ((this->length != matrix1.GetLength()) || (this->width != matrix1.GetWidth())) {
		throw Exception4();
	}
	Matrix matr = Matrix(this->length, this->width, this->matrix);
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < this->width; j++) {
			if (Overflow(matrix[i][j], -matrix1.GetElem(i, j))) {
				matr.SetElem(i, j, GetElem(i, j) - matrix1.GetElem(i, j));
			}
			else {
				return Zero;
			}
		}
	}
	return matr;
}
Matrix Matrix::operator*(Matrix matrix1)
{
	
		if (this->width != matrix1.GetLength()) {
			throw Exception4();
		}
	
	Matrix matr = Matrix(this->length, matrix1.GetWidth());

	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < matrix1.GetWidth(); j++) {
			matr.SetElem(i, j, 0);
			for (int k = 0; k < matrix1.GetWidth(); k++) {
				matr.SetElem(i, j, matr.GetElem(i, j) + this->GetElem(i, k) * matrix1.GetElem(k, j));
			}
		}
	}
	return matr;
}

Matrix Matrix::operator/(Matrix matrix1) {
	return Zero;
}

Matrix & Matrix::operator+=(double a)
{
	if (this->GetLength() != this->GetWidth()) {
		/*double ** mat = new double*[1];
		for (int i = 0; i < 1; i++) {
			mat[i] = new double[1];
		}
		mat[0][0] = 0;
		Matrix matr = Matrix(1, 1, mat);
		return matr;*/
		throw Exception4();
	}
	for (int i = 0; i < this->GetLength(); i++) {
		if (Overflow(matrix[i][i], a)) {
			this->SetElem(i, i, this->GetElem(i, i) + a);
		}
		else {
			*this = Zero;
			return *this;
		}
		
	}
	return *this;
}
Matrix & Matrix::operator+=(string str)
{
	const char *line = str.c_str();
	double a = atof(line);
	if (a != 0) {
		*this = *this + a;
		return *this;
	}

	Matrix A = StringToMatrix(str);
	*this = *this + A;
	return *this;
}
Matrix & Matrix::operator-=(double a)
{
	if (this->GetLength() != this->GetWidth()) {
		throw Exception4();
		*this = Zero;
		return *this;
	}
	for (int i = 0; i < this->GetLength(); i++) {
		if (Overflow(matrix[i][i], -a)) {
			this->SetElem(i, i, this->GetElem(i, i) - a);
		}
		else {
			*this = Zero;
			return *this;
		}
	}
	return *this;
}
Matrix & Matrix::operator-=(string str)
{
	const char *line = str.c_str();
	double a = atof(line);
	if (a != 0) {
		*this = *this - a;
		return *this;
	}

	Matrix A = StringToMatrix(str);
	*this = *this - A;
	return *this;
}
Matrix & Matrix::operator*=(double a)
{
	for (int i = 0; i < this->GetLength(); i++) {
		for (int j = 0; j < width; j++) {
			SetElem(i, j, GetElem(i, j) * a);
		}
	}
	return *this;
}
Matrix & Matrix::operator*=(string str)
{
	const char *line = str.c_str();
	double a = atof(line);
	if (a != 0) {
		*this = *this * a;
		return *this;
	}

	Matrix A = StringToMatrix(str);
	*this = *this * A;
	return *this;
}
Matrix & Matrix::operator/=(double a)
{
	if (a == 0) {
		throw Exception3();
		*this = Zero;
		return *this;
	}
	for (int i = 0; i < this->GetLength(); i++) {
		for (int j = 0; j < width; j++) {
			SetElem(i, j, GetElem(i, j) / a);
		}
	}
	return *this;
}
Matrix & Matrix::operator/=(string str)
{
	const char *line = str.c_str();
	double a = atof(line);
	if (a != 0) {
		*this = *this / a;
		return *this;
	}

	Matrix A = StringToMatrix(str);
	*this = *this / A;
	return *this;
}
Matrix & Matrix::operator+=(Matrix matrix1)
{
	if ((this->length != matrix1.GetLength()) || (this->width != matrix1.GetWidth())) {
		throw Exception4();
		*this = Zero;
		return *this;
	}
	//Matrix matr = Matrix(this->length, this->width, this->matrix);
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < this->width; j++) {
			if (Overflow(matrix[i][j], matrix1.GetElem(i, j))) {
				this->SetElem(i, j, this->GetElem(i, j) + matrix1.GetElem(i, j));
			}
			else {
				*this = Zero;
				return *this;
			}
			
		}
	}
	return *this;
}
Matrix & Matrix::operator-=(Matrix matrix1)
{
	if ((this->length != matrix1.GetLength()) || (this->width != matrix1.GetWidth())) {
		throw Exception4();
		*this = Zero;
		return *this;
	}
	//Matrix matr = Matrix(this->length, this->width, this->matrix);
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < this->width; j++) {
			if (Overflow(matrix[i][j], -matrix1.GetElem(i, j))) {
				this->SetElem(i, j, this->GetElem(i, j) - matrix1.GetElem(i, j));
			}
			else {
				*this = Zero;
				return *this;
			}
		}
	}
	return *this;
}
Matrix & Matrix::operator*=(Matrix matrix1)
{
	if (this->width != matrix1.GetLength()) {
		throw Exception4();
		*this = Zero;
		return *this;
	}
	Matrix matr = Matrix(this->length, matrix1.GetWidth());

	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < matrix1.GetWidth(); j++) {
			matr.SetElem(i, j, 0);
			for (int k = 0; k < matrix1.GetWidth(); k++) {
				matr.SetElem(i, j, matr.GetElem(i, j) + this->GetElem(i, k) * matrix1.GetElem(k, j));
			}
		}
	}
	this->length = matr.GetLength();
	this->width = matr.GetWidth();
	for (int i = 0; i < this->length; i++) {
		delete this->matrix[i];
	}
	this->matrix = new double*[this->length];
	for (int i = 0; i < this->length; i++) {
		this->matrix[i] = new double[this->width];
	}
	return *this;
}
Matrix & Matrix::operator/=(Matrix matrix1) {
	throw Exception3();
	*this = Zero;
	return *this;
}

Matrix & Matrix::operator++()
{
	if (this->length != this->width) {
		throw Exception4();
		*this = Zero;
		return *this;
	}
	for (int i = 0; i < this->GetLength(); i++) {
		if (Overflow(matrix[i][i], 1)) {
			this->SetElem(i, i, this->GetElem(i, i) + 1);
		}
		else {
			*this = Zero;
			return *this;
		}
		
	}
	return *this;
}
Matrix Matrix::operator++(int) {
	Matrix temp = *this;
	if (this->length != this->width) {
		throw Exception4();
		*this = Zero;
		return *this;
	}
	for (int i = 0; i < this->GetLength(); i++) {
		if (Overflow(matrix[i][i], 1)) {
			this->SetElem(i, i, this->GetElem(i, i) + 1);
		}
		else {
			*this = Zero;
			return *this;
		}
		
	}
	return temp;
}
Matrix & Matrix::operator--()
{
	if (this->length != this->width) {
		throw Exception4();
		*this = Zero;
		return *this;
	}
	for (int i = 0; i < this->GetLength(); i++) {
		if (Overflow(matrix[i][i], -1)) {
			this->SetElem(i, i, this->GetElem(i, i) - 1);
		}
		else {
			*this = Zero;
			return *this;
		}
	}
	return *this;
}
Matrix Matrix::operator--(int) {
	Matrix temp = *this;
	if (this->length != this->width) {
		/*Matrix matr = Matrix(1, 1);
		matr.SetElem(0, 0, 0);
		this->length = matr.GetLength();
		this->width = matr.GetWidth();
		for (int i = 0; i < this->length; i++) {
			delete this->matrix[i];
		}
		this->matrix = new double*[this->length];
		for (int i = 0; i < this->length; i++) {
			this->matrix[i] = new double[this->width];
		}*/
		throw Exception4();
		*this = Zero;
		return *this;
	}
	for (int i = 0; i < this->GetLength(); i++) {
		if (Overflow(matrix[i][i], 1)) {
			this->SetElem(i, i, this->GetElem(i, i) + 1);
		}
		else {
			*this = Zero;
			return *this;
		}
	}
	return temp;
}

bool Matrix::operator>(Matrix matrix1)
{
	double a = this->GetSumOfElements(*this); //??? will it work???
	double b = GetSumOfElements(matrix1);
	if (a > b) {
		return true;
	}
	return false;
}
bool Matrix::operator<(Matrix matrix1)
{
	double a = this->GetSumOfElements(*this); //??? will it work???
	double b = GetSumOfElements(matrix1);
	if (a < b) {
		return true;
	}
	return false;
}
bool Matrix::operator>=(Matrix matrix1)
{
	double a = this->GetSumOfElements(*this); //??? will it work???
	double b = GetSumOfElements(matrix1);
	if (a >= b) {
		return true;
	}
	return false;
}
bool Matrix::operator<=(Matrix matrix1)
{
	double a = this->GetSumOfElements(*this); //??? will it work???
	double b = GetSumOfElements(matrix1);
	if (a <= b) {
		return true;
	}
	return false;
}
bool Matrix::operator==(Matrix matrix1)
{
	double a = this->GetSumOfElements(*this); //??? will it work???
	double b = GetSumOfElements(matrix1);
	if (a == b) {
		return true;
	}
	return false;
}

bool Matrix::operator!=(Matrix matrix1)
{
	double a = this->GetSumOfElements(*this); //??? will it work???
	double b = GetSumOfElements(matrix1);
	if (a != b) {
		return true;
	}
	return false;
}

const double * Matrix::operator[](int i)
{
	if ((i < 0) || (i >= length)) {
		throw Exception2();
	}
	return matrix[i];
}

Matrix& Matrix::operator=(const Matrix & object)
{
	if (this != &object) {
		for (int i = 0; i < length; i++) {
			delete matrix[i];
		}
		length = object.GetConstLength();
		width = object.GetConstWidth();
		Create();
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {
				matrix[i][j] = object.GetConstElem(i, j);// some error happens here
			}
		}
	}
	return *this;
}

/*ostream & Matrix::operator<<(ostream & cout, const Matrix& object)
{
	
}*/



void Matrix::SetElem(int i, int j, double number)
{
	if ((i < 0) || (i >= length)) {
		throw Exception2();
	}
	else if ((j < 0) || (j >= width)) {
		throw Exception2();
	}
	matrix[i][j] = number;
}

double Matrix::GetElem(int i, int j)
{
	if ((i < 0) || (i >= length)) {
		throw Exception2();
	}
	else if ((j < 0) || (j >= width)) {
		throw Exception2();
	}
	return matrix[i][j];
}

double Matrix::GetConstElem(int i, int j) const
{
	if ((i < 0) || (i >= length)) {
		throw Exception2();
	}
	else if ((j < 0) || (j >= width)) {
		throw Exception2();
	}
	return matrix[i][j];
}

int Matrix::GetLength()
{
	return length;
}

int Matrix::GetConstLength() const
{
	return length;
}

int Matrix::GetWidth()
{
	return width;
}

int Matrix::GetConstWidth() const
{
	return width;
}

double Matrix::GetSumOfElements(Matrix matrix)
{
	double sum = 0;
	for (int i = 0; i < matrix.GetLength(); i++) {
		for (int j = 0; j < matrix.GetWidth(); j++) {
			sum += matrix.GetElem(i, j);
		}
	}
	return sum;
}


Matrix::~Matrix()
{
	//cout << "matrix.destructor start(" << length << " , " << width << ")"<< endl;
	for (int i = 0; i < length; i++) {
		delete[] this->matrix[i];
	}
	delete[] this->matrix;
	//cout << "matrix.destructor end(" << length << " , " << width << ")" << endl;
}

ostream & operator<<(ostream & cout, const Matrix & object)
{
	for (int i = 0; i < object.GetConstLength(); i++) {
		for (int j = 0; j < object.GetConstWidth(); j++) {
			double a = object.GetConstElem(i, j);
			if ( a < 10000) {
				if (a < 1000) {
					if (a < 100) {
						if (a < 10) {
							cout << "    " << a;
						}
						else {
							cout << "   " << a;
						}
					}
					else {
						cout << "  " << a;
					}
				}
				else {
					cout << " " << a;
				}
			}
			else {
				cout << " " << a;
			}
		}
		cout << '\n';
	}
	return cout;
}

istream & operator>>(istream & cin, Matrix & object)
{
	double a;
	for (int i = 0; i < object.GetLength(); i++) {
		for (int j = 0; j < object.GetWidth(); j++) {
			cin >> a;
			object.SetElem(i, j, a);
		}
	}
	return cin;
}
