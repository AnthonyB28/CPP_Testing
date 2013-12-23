#ifndef _MATRIX_H
#define _MATRIX_H
#endif // _MATRIX_H
#include <iostream>

using namespace std;

class Matrix {
public:
    float **p;	// pointer to a pointer to a float
     int dx, dy;  // dimensions, dx by dy
	Matrix(int sizeX, int sizeY);
	Matrix();
	~Matrix();
	Matrix(const Matrix& m);
	Matrix& operator=(const Matrix& rhs);
	Matrix operator+(const Matrix & m);
	Matrix& operator+=(const Matrix & m);
	friend ostream &operator<<
		(ostream &out, const Matrix &m);
	float &operator()(int x, int y);
	friend Matrix operator*
		(const Matrix & m1, const Matrix & m2);
	friend Matrix operator*
		(float c, const Matrix & m2);
	friend Matrix operator*
		(const Matrix & m1, float c);


private:

	void allocArrays() {
		assert(dx>0);
		assert(dy>0);
		p = new float*[dx];
		for (int i = 0; i < dx; i++)	{
			p[i] = new float[dy];
		}
	}
};
