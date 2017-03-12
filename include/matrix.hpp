#include <fstream>
#include <iostream>
class Matrix
{
private:
	int row, column;
	int **arr;
public:
	Matrix(int side = 3);
	Matrix(int, int);
	~Matrix();
	Matrix(const Matrix&);
	void fill_matrix(const char*);
	void show_matrix() const;
	Matrix operator+(const Matrix&) const;
	Matrix operator*(const Matrix&) const;
	Matrix operator=(const Matrix&);
};
