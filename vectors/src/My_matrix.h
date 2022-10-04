#pragma once
#include "My_vectors.h"
#include <Vector>

class Matrix {
	int m = 0;
	int n = 0;
	Vector* data = 0;
public:
	Matrix();
	Matrix(int m, int n);
	Matrix(const Matrix& m);
	~Matrix();
	Matrix(std::vector<Vector> arr);
	int get_m() { return m; };
	int get_n() { return n; };
	Matrix operator+(const Matrix& m) const;
	Matrix& operator+=(const Matrix& m);
	Matrix& operator-=(const Matrix& m);
	Matrix operator*(const Matrix& m) const;
	Matrix operator*(double c) const;
	Matrix operator-(const Matrix& m) const;
	Matrix& operator=(const Matrix& m);
	Vector& operator[](int i);
	Vector operator[](int i) const;
	void resize(int NewM, int NewN);
	Matrix down_triangle(const Matrix& m, Vector& b, std::vector<int>& posMax);
	Matrix upper_triangle(const Matrix& m, Vector& b);
	bool proverka(const Matrix& m, const Vector& b);
	double Max(const Matrix& m, int k, int& pos);
	Matrix& swapper(Matrix& m);
	friend void swap(Matrix& m, int k1, int k2);
	friend std::ostream& operator<< (std::ostream& object, const Matrix& m);
	friend Matrix operator*(double c, const Matrix& m);
	friend bool operator==(const Matrix& m1, const Matrix& m2);
	friend bool operator!=(const Matrix& m1, const Matrix& m2);
};