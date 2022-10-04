#pragma once

class Vector {
	double *data = 0;
	int n = 0;
public:
	Vector();
	Vector(int n);
	Vector(const Vector& v);
	~Vector();
	int size();
	void resize(int NewSize);
	Vector& operator=(const Vector& v);
	Vector operator+(const Vector& v) const;
	Vector operator-(const Vector& v) const;
	Vector& operator+=(const Vector& v);
	Vector& operator-=(const Vector& v);
	Vector operator*(double c) const;
	double& operator[](int i);
	friend double dot(const Vector& v1, const Vector& v2);
	double operator[](int i) const;
	Vector& operator++();
	Vector operator++(int);
	friend std::ostream& operator<< (std::ostream& object, const Vector& c);
	friend Vector operator*(double c, const Vector& v);
	friend bool operator==(const Vector& v1, const Vector& v2);
	friend bool operator!=(const Vector& v1, const Vector& v2);
};