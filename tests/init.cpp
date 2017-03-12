#include <matrix.hpp>
#include <catch.hpp>

SCENARIO("matrix init", "[init]") {
	Matrix matr;
	REQUIRE(matr.rows() == 3);
	REQUIRE(matr.columns() == 3);
	Matrix matr2(5, 5);
	REQUIRE(matr2.rows() == 5);
	REQUIRE(matr2.columns() == 5);
	Matrix matr3(matr);
	REQUIRE(matr.rows() == 3);
	REQUIRE(matr.columns() == 3);
}
SCENARIO("matrix operators", "[operators]") {
	Matrix m1, m2, sum, comp;
	m1.fill_matrix("matrix/sources/matrix1.txt");
	m2.fill_matrix("matrix/sources/matrix2.txt");
	sum.fill_matrix("matrix/sources/matrix_sum.txt");
	comp.fill_matrix("matrix/sources/matrix_comp.txt");
	REQUIRE (sum == m1 + m2);
	REQUIRE (comp == m1 * m2);
}
