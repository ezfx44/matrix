#include <matrix.hpp>
#include <catch.hpp>
#include <string>

SCENARIO("matrix init w/o param", "[init w/o par]") {
	Matrix matrix;
	REQUIRE(matrix.rows() == 3);
	REQUIRE(matrix.columns() == 3);
	for (int i=0; i < matrix.rows(); i++) 
	{
		for (int j = 0; j < matrix.columns(); j++) 
		{
			REQUIRE(matrix.Element(i,j) == 0);
		}
	}
}

SCENARIO("matrix init with params", "[init w par]") {
	Matrix matrix(5, 5);
	REQUIRE(matrix.rows() == 5);
	REQUIRE(matrix.columns() == 5);
	for (int i = 0; i < matrix.rows(); i++) 
	{
		for (int j = 0; j < matrix.columns(); j++) 
		{
			REQUIRE(matrix.Element(i, j) == 0);
		}
	}
}

SCENARIO("matrix init copy", "[init copy]") {
	Matrix matrix1(2,2);
	Matrix matrix2(matrix1);
	REQUIRE(matrix1.rows() == matrix2.rows());
	REQUIRE(matrix1.columns() == matrix2.columns());
	for (int i = 0; i < matrix1.rows(); i++) 
	{
		for (int j = 0; j < matrix1.columns(); j++) 
		{
			REQUIRE(matrix1.Element(i,j) == matrix2.Element(i,j));
		}
	}
}

SCENARIO("matrix operator +", "[op+]") {
	Matrix matrix1(2, 2);
	Matrix matrix2(2, 2);
	std::ofstream test1("test1.txt");
	test1 << "1 2 3 4";
	test1.close();
	matrix1.fill("test1.txt");
	matrix2.fill("test1.txt");
	REQUIRE(matrix1.Element(0,0) + matrix2.Element(0,0) == 2);
	REQUIRE(matrix1.Element(0,1) + matrix2.Element(0,1) == 4);
	REQUIRE(matrix1.Element(1,0) + matrix2.Element(1,0) == 6);
	REQUIRE(matrix1.Element(1,1) + matrix2.Element(1,1) == 8);
}

SCENARIO("matrix operator *", "[op*]") {
	Matrix matrix1(2,2);
	Matrix matrix2(2,2);
	std::ofstream test2("test2.txt");
	test2 << "1 2 3 4";
	test2.close();
	matrix1.fill("test2.txt");
	matrix2.fill("test2.txt");
	REQUIRE(matrix1.Element(0,0) * matrix2.Element(0,0) + matrix1.Element(1,0) * matrix2.Element(0,1) == 7);
	REQUIRE(matrix1.Element(0,1) * matrix2.Element(0,0) + matrix1.Element(1,1) * matrix2.Element(0,1) == 10);
	REQUIRE(matrix1.Element(0,0) * matrix2.Element(1,0) + matrix1.Element(1,0) * matrix2.Element(1,1) == 15);
	REQUIRE(matrix1.Element(0,1) * matrix2.Element(1,0) + matrix1.Element(1,1) * matrix2.Element(1,1) == 22);
}
	
SCENARIO("matrix operator ==" , "[op==]") {
	Matrix matrix1(2,2);
	Matrix matrix2(2,2);
	std::ofstream test3("test3.txt");
	test3 << "1 2 3 4";
	test3.close();
	matrix1.fill("test3.txt");
	matrix2.fill("test3.txt");
	for (int i = 0; i < matrix1.rows(); i++) 
	{
		for (int j = 0; j < matrix1.columns(); j++) 
		{
			REQUIRE(matrix1.Element(i,j) == matrix2.Element(i,j));
		}
	}
	
}

SCENARIO("matrix operator =" , "[op=]") {
	Matrix matrix1(2,2);
	Matrix matrix2(2,2);
	std::ofstream test4("test4.txt");
	test4 << "1 2 3 4";
	test4.close();
	matrix1.fill("test4.txt");
	matrix2 = matrix1;
	REQUIRE(matrix1.Element(0,0) == 1);
	REQUIRE(matrix1.Element(0,1) == 2);
	REQUIRE(matrix1.Element(1,0) == 3);
	REQUIRE(matrix1.Element(1,1) == 4);
	
}
