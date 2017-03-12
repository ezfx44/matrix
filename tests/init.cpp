#include <matrix.hpp>
#include <catch.hpp>

SCENARIO("matrix init", "[init]") {
	Matrix matr;
	REQUIRE(matr.row == 3);
	REQUIRE(matr.column == 3);
}
