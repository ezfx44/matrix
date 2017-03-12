#include <matrix.hpp>
#include <catch.hpp>

SCENARIO("matrix init", "[init]") {
	Matrix matr;
	REQUIRE(matr.rows() == 3);
	REQUIRE(matr.columns() == 3);
	Matrix matr2(5, 5);
	REQUIRE(matr2.rows() == 5);
	REQUIRE(matr2.columns() == 5);
}
