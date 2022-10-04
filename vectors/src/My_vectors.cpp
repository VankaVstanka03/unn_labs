#include <iostream>
#include "My_vectors.h"

Vector::Vector():n(0),data(0){}

Vector::Vector(int n) {
	if (n < 0) {
		std::cout << "ERROR in Vector::Vector(int n)" << std::endl;
		this->n = 0;
	}
	else {
		this->n = n;
		this->data = new double[n];
		for (int i = 0; i < n; i++) {
			this->data[i] = 0;
		}
	}

}

Vector::Vector(const Vector& v) {
	resize(v.n);
	this->n = v.n;
	for (int i = 0; i < v.n; i++) {
		this->data[i] = v.data[i];
	}
}

Vector::~Vector() {
	delete[] data;
}

int Vector::size(){
	return this->n;
}

void Vector::resize(int NewSize) {
	double* datacopy = new double[NewSize];
	int minSize = this->n < NewSize ? this->n : NewSize;
	for (int i = 0; i < minSize; i++) {
		datacopy[i] = this->data[i];
	}
	for (int i = minSize; i < NewSize; i++) {
		datacopy[i] = 0;
	}
	delete[] this->data;
	this->data = datacopy;
	this->n = NewSize;
}

Vector& Vector::operator=(const Vector& v) {
	if (this->n != v.n) {
		resize(v.n);
		for (int i = 0; i < v.n; i++) {
			this->data[i] = v.data[i];
		}
		return *this;
	}
	for (int i = 0; i < v.n; i++) {
		this->data[i] = v.data[i];
	}
	return *this;
}

Vector Vector::operator+(const Vector& v) const {
	if (this->n > v.n) {
		Vector c(this->n);
		for (int i = 0; i < v.n; i++) {
			c.data[i] = this->data[i] + v.data[i];
		}
		for (int i = v.n; i < this->n; i++) {
			c.data[i] = this->data[i];
		}
		return c;
	}
	else if (this->n == v.n) {
		Vector c(this->n);
		for (int i = 0; i < v.n; i++) {
			c.data[i] = this->data[i] + v.data[i];
		}
		return c;
	}
	if (this->n < v.n) {
		Vector c(v.n);
		for (int i = 0; i < this->n; i++) {
			c.data[i] = this->data[i] + v.data[i];
		}
		for (int i = this->n; i < v.n; i++) {
			c.data[i] = v.data[i];
		}
		return c;
	}
}

Vector Vector::operator-(const Vector& v) const {
	if (this->n > v.n) {
		Vector c(this->n);
		for (int i = 0; i < v.n; i++) {
			c.data[i] = this->data[i] - v.data[i];
		}
		for (int i = v.n; i < this->n; i++) {
			c.data[i] = this->data[i];
		}
		return c;
	}
	else if (this->n == v.n) {
		Vector c(this->n);
		for (int i = 0; i < v.n; i++) {
			c.data[i] = this->data[i] - v.data[i];
		}
		return c;
	}
	if (this->n < v.n) {
		Vector c(v.n);
		for (int i = 0; i < this->n; i++) {
			c.data[i] = this->data[i] - v.data[i];
		}
		for (int i = this->n; i < v.n; i++) {
			c.data[i] = v.data[i];
		}
		return c;
	}
}

Vector& Vector::operator+=(const Vector& v) {
	if (this->n > v.n) {
		for (int i = 0; i < v.n; i++) {
			this->data[i] = this->data[i] + v.data[i];
		}
		for (int i = v.n; i < this->n; i++) {
			this->data[i] = this->data[i];
		}
		return *this;
	}
	else if (this->n == v.n) {
		for (int i = 0; i < v.n; i++) {
			this->data[i] = this->data[i] + v.data[i];
		}
		return *this;
	}
	if (this->n < v.n) {
		resize(v.n);
		for (int i = 0; i < this->n; i++) {
			this->data[i] = this->data[i] + v.data[i];
		}
		for (int i = this->n; i < v.n; i++) {
			this->data[i] = v.data[i];
		}
		return *this;
	}
}

Vector& Vector::operator-=(const Vector& v) {
	if (this->n > v.n) {
		for (int i = 0; i < v.n; i++) {
			this->data[i] = this->data[i] - v.data[i];
		}
		for (int i = v.n; i < this->n; i++) {
			this->data[i] = this->data[i];
		}
		return *this;
	}
	else if (this->n == v.n) {
		for (int i = 0; i < v.n; i++) {
			this->data[i] = this->data[i] - v.data[i];
		}
		return *this;
	}
	if (this->n < v.n) {
		resize(v.n);
		for (int i = 0; i < this->n; i++) {
			this->data[i] = this->data[i] - v.data[i];
		}
		for (int i = this->n; i < v.n; i++) {
			this->data[i] = v.data[i];
		}
		return *this;
	}
}

Vector Vector::operator*(double c) const {
	Vector c1(this->n);
	for (int i = 0; i < n; i++) {
		c1.data[i] = c * this->data[i];
	}
	return c1;
}

double& Vector::operator[](int i) {
	return this->data[i];
}

//double Vector::dot(const Vector& v) const{
//	double res = 0;
//	for (int i = 0; i < this->n; i++) {
//		res += this->data[i] * v.data[i];
//	}
//	return res;
//}

double Vector::operator[](int i) const {
	return this->data[i];
}

Vector& Vector::operator++(){
	for (int i = 0; i < this->n; i++) {
		this->data[i] += 1;
	}
	return *this;
}

Vector Vector::operator++(int){
	Vector temp(*this);
	this->operator++();
	return temp;
}

double dot(const Vector& v1, const Vector& v2){
	double res = 0;
	for (int i = 0; i < v1.n; i++) {
		res += v1.data[i] * v2.data[i];
	}
	return res;
}

std::ostream& operator<<(std::ostream& object, const Vector& c) {
	for (int i = 0; i < c.n; i++) {
		object << "[" << c.data[i] << "]" << "\n";
	}
	return object;
}

Vector operator*(double c, const Vector& v) {
	Vector c1(v.n);
	for (int i = 0; i < v.n; i++) {
		c1.data[i] = c * v.data[i];
	}
	return c1;
}

bool operator==(const Vector& v1, const Vector& v2){
	if (v1.n != v2.n) {
		return false;
	}
	else {
		for (int i = 0; i < v1.n; i++) {
			if (v1.data[i] != v2.data[i]) {
				return false;
			}
		}
		return true;
	}
}

bool operator!=(const Vector& v1, const Vector& v2){
	return !(v1 == v2);
}
