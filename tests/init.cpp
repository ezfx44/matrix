#include <matrix.hpp>
#include <catch.hpp>
#include <string>

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

SCENARIO("all-in-one test for methods", "[methods]") {
	std::ofstream mx1("mx1.txt");
	mx1 << "1 2 3 4 5 6 7 8 9";
	mx1.close();
	std::ofstream mx2("mx2.txt");
	mx2 << "9 8 7 6 5 4 3 2 1";
	mx2.close();
	std::ofstream mx_sum("mx_sum.txt");
	mx_sum << "10 10 10 10 10 10 10 10 10";
	mx_sum.close();
	std::ofstream mx_comp("mx_comp.txt");
	mx_comp << "30 24 18 84 69 54 138 114 90";
	mx_comp.close();
	Matrix m1, m2, sum, comp;
	m1.fill_matrix("mx1.txt");
	m2.fill_matrix("mx2.txt");
	sum.fill_matrix("mx_sum.txt");
	comp.fill_matrix("mx_comp.txt");
	REQUIRE (sum == m1 + m2);
	REQUIRE (comp == m1 * m2);
	m1 = m2;
	REQUIRE (m1 == m2);
}
