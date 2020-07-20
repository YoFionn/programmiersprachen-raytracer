#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Sphere.cpp"
#include "Box.cpp"
#include "ray.hpp"
#include "hitpoint.hpp"
#include <glm/glm.hpp >
#include <glm/gtx/intersect.hpp>
#include <iostream>

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

TEST_CASE("intersect_ray_sphere", "[intersect]") {
	//Ray
	glm::vec3 ray_origin{ 0.0f, 0.0f, 0.0f };
	// ray direction has to be normalized !
	// you can use:
	//	v = glm::normalize(some_vector)
	glm::vec3 ray_direction{ 0.0f, 0.0f, 1.0f };
	//Sphere

	glm::vec3 sphere_center{ 0.0f, 0.0f, 5.0f };
	float sphere_radius{ 1.0f };

	float distance = 0.0f;
	auto result = glm::intersectRaySphere(
		ray_origin, ray_direction,
		sphere_center,
		sphere_radius * sphere_radius, //square radius!!
		distance);
}

TEST_CASE("intersect_ray_sphere_testzz", "[intersect]") {
	Sphere s1{ 7.0f, {25.0f, 68.0f, 12.0f}, "Krueger", {3.0f, 5.0f, 1.0f} };
	Sphere s2{ 1.0f, {0.0f, 0.0f, 0.0f}, "Schroedinger", {3.0f, 5.0f, 1.0f} };
	Ray r1{ {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f} };
	HitPoint h1{s1.intersect(r1)};
	HitPoint h2{ s2.intersect(r1) };
	REQUIRE(h1.intersect == false);
	REQUIRE(h2.intersect == true);



}


int main(int argc, char *argv[])
{
	Sphere print_s_test{ 7.0f, {25.0f, 68.0f, 12.0f}, "Krueger", {3.0f, 5.0f, 1.0f} };
	Box print_b_test{ {3.0f, 5.0f, 1.0f}, {25.0f, 68.0f, 12.0f}, "Schroedinger", {3.0f, 5.0f, 1.0f} };
	std::cout << print_s_test << std::endl;
	std::cout << print_b_test << std::endl;

	Sphere* s = new Sphere{ 7.0f, {25.0f, 68.0f, 12.0f}, "Krueger", {3.0f, 5.0f, 1.0f} };
	Box* b = new Box{ {3.0f, 5.0f, 1.0f}, {25.0f, 68.0f, 12.0f}, "Schroedinger", {3.0f, 5.0f, 1.0f} };
	delete s;	//hier wird der Destruktor aufgerufen
	delete b;	//hier wird der Destruktor aufgerufen
	return Catch::Session().run(argc, argv);
}
