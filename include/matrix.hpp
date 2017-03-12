#include <fstream>
#include <iostream>
class Matrix
{
private:
	int row, column;
	int **arr;
public:
	auto rows() -> unsigned int;
    	auto columns() -> unsigned int;
	Matrix(int side = 3);
	Matrix(int, int);
	~Matrix();
	Matrix(const Matrix&);
	void fill_matrix(const char*);
	void show_matrix() const;
	Matrix operator+(const Matrix&) const;
	Matrix operator*(const Matrix&) const;
	Matrix operator=(const Matrix&);
	bool operator==(const Matrix&) const;
	friend std::istream& operator >> (std::istream&, Matrix&);
	friend std::ostream& operator << (std::ostream&, const Matrix&);
};
