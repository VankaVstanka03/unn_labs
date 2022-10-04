#include <iostream>
#include "My_matrix.h"
#include "My_vectors.h"
#include <vector>
#include <cmath>

Matrix::Matrix():n(0), m(0), data(0){}

Matrix::Matrix(int m, int n){
	this->data = new Vector[m];
	for (int i = 0; i < m; i++) {
		this->data[i].resize(n);
	}
	this->m = m;
	this->n = n;
}

Matrix::Matrix(const Matrix& m){
	resize(m.m, m.n);
	this->m = m.m;
	this->n = m.n;
	for (int i = 0; i < this->m; i++) {
		data[i] = m.data[i];
	}
}

Matrix::~Matrix(){
	delete[] data;
}

Matrix::Matrix(std::vector<Vector> arr){
	this->m = arr.size();
	this->n = arr[0].size();
	data = new Vector[m];
	for (int i = 0; i < m; i++) {
		data[i] = arr[i];
	}
}


Matrix Matrix::operator+(const Matrix& m) const {
	Matrix res(this->m, this->n);
	if (this->m != m.m) {
		std::cout << "Error" << std::endl;
	}
	for (int i = 0; i < this->m; i++) {
		res.data[i] = this->data[i] + m.data[i];
	}
	return res;
}

Matrix& Matrix::operator+=(const Matrix& m){
	if (this->m != m.m) {
		std::cout << "Error" << std::endl;
	}
	for (int i = 0; i < this->m; i++) {
		this->data[i] += m.data[i];
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& m){
	if (this->m != m.m) {
		std::cout << "Error" << std::endl;
	}
	for (int i = 0; i < this->m; i++) {
		this->data[i] -= m.data[i];
	}
	return *this;
}

Matrix Matrix::operator*(const Matrix& m) const{
	if (this->n == m.m) {
		Matrix res(this->m, m.n);
		for (int i = 0; i < this->m; i++) {
			for (int j = 0; j < m.n; j++) {
				res[i][j] = 0;
				for (int k = 0; k < this->n; k++) {
					res[i][j] += this->data[i][k] * m.data[k][j];
				}
			}
		}
		return res;
	}
	else {
		std::cout << "Error" << std::endl;
	}
}

Matrix Matrix::operator*(double c) const{
	Matrix res(this->m, this->n);
	for (int i = 0; i < this->m; i++) {
		res.data[i] = this->data[i] * c;
	}
	return res;
}

Matrix Matrix::operator-(const Matrix& m) const{
	Matrix res(this->m, this->n);
	if (res.m != m.m) {
		std::cout << "Error" << std::endl;
	}
	for (int i = 0; i < res.m; i++) {
		res.data[i] = this->data[i] - m.data[i];
	}
	return res;
}

Matrix& Matrix::operator=(const Matrix& m){
	if (this == &m) {
		return *this;
	}
	resize(m.m, m.n);
	return *this;
}

Vector& Matrix::operator[](int i) {
	return data[i];
}

Vector Matrix::operator[](int i) const{
	return data[i];
}

void Matrix::resize(int NewM, int NewN){
	int minsizeM;
	if (this->m < NewM) {
		minsizeM = this->m;
	}
	else if (this->m > NewM) {
		minsizeM = NewM;
	}
	else {
		minsizeM = NewM;
	}
	Vector* datacopy = new Vector[NewM];
	for (int i = 0; i < minsizeM; i++) {
		datacopy[i].resize(NewN);
		datacopy[i]=data[i];
	}
	for (int i = minsizeM; i < NewM;i++) {
		//datacopy[i] = 0;
		datacopy[i].resize(NewN);
	}
	delete[] data;
	this->data = datacopy;
	this->m = NewM;
	this->n = NewN;

}

Matrix Matrix::down_triangle(const Matrix& m, Vector& b, std::vector<int>& posMax){
	Matrix tri = m;
	Vector copy(m.m);
	//std::Vector<int> posMax;
	copy = b;
	//for (int i = 0; i < tri.m; i++) {
	//	for (int j = 0; j < tri.n; j++) {
	//		tri[i][j] = m[j][i];
	//	}
	//}
	int position;
	double tmp;
	int min = tri.m < tri.n ? tri.m : tri.n;
	int max = tri.m > tri.n ? tri.m : tri.n;
	if (tri.m >= tri.n) {
		for (int i = 0; i < min; i++) {
			tmp = tri.Max(tri, i, position);
			posMax[i] = position;
			if ((tmp < 1e-10 && tmp > 1e-20)||(tmp < -1e-20 && tmp > -1e-10) ){
				tmp = 0;
				tri[i][position] = 0;
			}
			if (tmp != 0) {
				copy[i] = copy[i] / tmp;
				for (int k = 0; k < tri.n; k++) {
					tri[i][k] = tri[i][k] / tmp;
				}
				tmp = 1;
				for (int j = i + 1; j < max; j++) {
					copy[j] = tmp * copy[j] - tri[j][position] * copy[i];
					tri[j] = tmp * tri[j] - tri[j][position] * tri[i];
					if ((copy[j] < 1e-10 && copy[j] > 1e-20) || (copy[j] < -1e-20 && copy[j] > -1e-10)) {
						copy[j] = 0;
					}
				}
			}
		}
		for (int i = min; i < max; i++) {
			tmp = tri.Max(tri, i, position);
			if ((tmp < 1e-10 && tmp > 1e-20) || (tmp < -1e-20 && tmp > -1e-10)) {
				tmp = 0;
				tri[i][position] = 0;
			}
			if (tmp != 0) {
				copy[i] = copy[i] / tmp;
				for (int k = 0; k < tri.n; k++) {
					tri[i][k] = tri[i][k] / tmp;
				}
				tmp = 1;
			}
		}
	}
	else {
		for (int i = 0; i < min; i++) {
			tmp = tri.Max(tri, i, position);
			posMax[i] = position;
			if ((tmp < 1e-10 && tmp > 1e-20) || (tmp < -1e-20 && tmp > -1e-10)) {
				tmp = 0;
				tri[i][position] = 0;
			}
			if (tmp != 0) {
				copy[i] = copy[i] / tmp;
				for (int k = 0; k < tri.n; k++) {
					tri[i][k] = tri[i][k] / tmp;
				}
				tmp = 1;
				for (int j = i + 1; j < min; j++) {
					tri[j] = tmp * tri[j] - tri[j][position] * tri[i];
					copy[j] = copy[j] - tri[j][position] * copy[i];
					if ((copy[j] < 1e-10 && copy[j] > 1e-20) || (copy[j] < -1e-20 && copy[j] > -1e-10)) {
						copy[j] = 0;
					}
				}
				//std::cout << copy << std::endl;
			}
		}
	}
	b = copy;
	return tri;
}

Matrix Matrix::upper_triangle(const Matrix& m, Vector& b){
	Matrix up_tri = m;
	Vector copy = b;
	double tmp;
	int position;
	int min = up_tri.m < up_tri.n ? up_tri.m : up_tri.n;
	int max = up_tri.m > up_tri.n ? up_tri.m : up_tri.n;
	if (up_tri.m >= up_tri.n) {
		for (int i = 1; i < max; i++) {
			tmp = up_tri.Max(up_tri, i, position);
			if (tmp != 0) {
				for (int j = 0; j < i; j++) {
					copy[j] = copy[j] - up_tri[j][position] * copy[i];
					up_tri[j] = tmp * up_tri[j] - up_tri[j][position] * up_tri[i];
				}
			}
		}
	}
	else if (up_tri.m < up_tri.n) {
		for (int i = 1; i < min; i++) {
			tmp = up_tri.Max(up_tri, i, position);
			if (tmp != 0) {
				for (int j = 0; j < i; j++) {
					copy[j] = copy[j] - up_tri[j][position] * copy[i];
					up_tri[j] = tmp * up_tri[j] - up_tri[j][position] * up_tri[i];
					//copy[j] = copy[j] - up_tri[j][position] * copy[i];
				}
			}
			//std::cout << copy << std::endl;
		}
	}
	b = copy;
	return up_tri;
}

bool Matrix::proverka(const Matrix& m, const Vector& b){
	Vector proverka(m.n);
	for (int i = 0; i < m.m; i++) {
		if (m[i] == proverka && b[i] != 0) {
			return true;
		}
	}
	return false;
}

void swap(Matrix& m, int k1, int k2){
	Vector tmp;
	tmp = m[k1];
	m[k1] = m[k2];
	m[k2] = tmp;
}

Matrix& Matrix::swapper(Matrix& m){
	double max;
	int position;
	Vector proverka(m.n);
	for (int i = 0; i < m.m; i++) {
		max = Max(m, i, position);
		if (position != i && m[i] != proverka) {
			swap(m, i, position);
		}
		if (position > m.m) {
			swap(m, m.m, position);
		}
	}
	return m;
}

double Matrix::Max(const Matrix& m, int k, int& pos){
	double max = m[k][0];
	pos = 0;
	for (int i = 1; i < m.n; i++) {
		if (sqrt(m[k][i] * m[k][i]) > sqrt(max * max)) {
			max = m[k][i];
			pos = i;
		}
	}
	if (max == 0.0) {
		pos = -1;
	}
	return max;
}

std::ostream& operator<<(std::ostream& object, const Matrix& m){
	for (int i = 0; i < m.m; i++) {
		for (int j = 0; j < m.n; j++) {
			object << m.data[i][j] << " ";
		}
		object << "\n";
	}
	return object;
}

Matrix operator*(double c, const Matrix& m){
	Matrix res(m.m, m.n);
	for (int i = 0; i < m.m; i++) {
		res.data[i] = m.data[i] * c;
	}
	return res;
}

bool operator==(const Matrix& m1, const Matrix& m2){
	if ((m1.m != m2.m) || (m1.n != m2.n)) {
		return false;
	}
	else {
		for (int i = 0; i < m1.m; i++) {
			if (m1.data[i] != m2.data[i]) {
				return false;
			}
		}
		return true;
	}
}

bool operator!=(const Matrix& m1, const Matrix& m2){
	return !(m1 == m2);
}
