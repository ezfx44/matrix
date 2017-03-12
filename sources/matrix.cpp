#include "matrix.hpp"
Matrix::Matrix(int side) : row(side), column(side)
{
	arr = new int*[row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[column];
		for (int j = 0; j < column; j++)
		{
			arr[i][j] = 0;
		}
	}
}

Matrix::Matrix(int r, int c) : row(r), column(c)
{
	arr = new int*[r];
	for (int i = 0; i < r; i++)
	{
		arr[i] = new int[c]{0};
	}
}

Matrix::Matrix(const Matrix& a) :row(a.row), column(a.column)
{
	arr = new int*[row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[column];
		for (int j = 0; j < column; j++)
		{
			arr[i][j] = a.arr[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < row; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

void Matrix::fill_matrix(const char* name)
{
	std::ifstream fin(name);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			fin >> arr[i][j];
		}
	}
}

void Matrix::show_matrix() const
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			std::cout.width(4);
			std::cout << arr[i][j] << " ";
		}
		std::cout << '\n';
	}
	std::cout << std::endl;
}

Matrix Matrix::operator+(const Matrix& m) const
{
	Matrix help(row, column);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			help.arr[i][j] = arr[i][j] + m.arr[i][j];
		}
	}
	return help;
}



Matrix Matrix::operator*(const Matrix& m) const
{
	Matrix help(row, column);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			help.arr[i][j] = 0;
			for (int k = 0; k < m.row; k++)
			{
				help.arr[i][j] += arr[i][k] * m.arr[k][j];
			}
		}
	}
	return help;
}

Matrix Matrix::operator=(const Matrix& x)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			arr[i][j] = x.arr[i][j];
		}
	}
	return *this;
}
