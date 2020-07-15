#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Sphere.cpp"
#include "Box.cpp"

TEST_CASE("Berechnen der Operfläche und des Volumen der Sphäre","[aufgabe 5.2]") {
	Sphere s1{};
	Sphere s2{ 4.5f };
	Sphere s3{ 0.0f };
	Sphere s4{ -4.5f };

	REQUIRE(s1.area() == Approx(12.56637));
	REQUIRE(s2.area() == Approx(254.469));
	REQUIRE(s3.area() == Approx(0.0));
	REQUIRE(s4.area() == Approx(254.469));
	REQUIRE(s1.volumen() == Approx(4.18879));
	REQUIRE(s2.volumen() == Approx(381.704));
	REQUIRE(s3.volumen() == Approx(0.0));
	REQUIRE(s4.volumen() == Approx(381.704));
}

TEST_CASE("Berechnen der Operfläche und des Volumen der Box", "[aufgabe 5.2]") {
	Box b1{};
	Box b2{ {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f} };
	Box b3{ {1.0f, 1.0f, 1.0f}, {6.0f, 6.0f, 6.0f} };

	REQUIRE(b1.area() == Approx(6.0f));
	REQUIRE(b2.area() == Approx(0.0f));
	REQUIRE(b3.area() == Approx(30.0f));
	REQUIRE(b1.volumen() == Approx(1.0f));
	REQUIRE(b2.volumen() == Approx(0.0f));
	REQUIRE(b3.volumen() == Approx(125.0f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
