#include <fstream>
#include <iostream>
class Matrix
{
private:
	int row, column;
	int **arr;
public:
	auto rows() const -> unsigned int;
    	auto columns() const -> unsigned int;
	Matrix(int side = 3);
	Matrix(int, int);
	~Matrix();
	Matrix(const Matrix&);
	int Element(int, int) const;
	Matrix operator+(const Matrix&) const;
	Matrix operator*(const Matrix&) const;
	Matrix operator=(const Matrix&);
	bool operator==(const Matrix&) const;
	friend std::istream& operator >> (std::istream&, Matrix&);
	friend std::ostream& operator << (std::ostream&, const Matrix&);
};
