#include "Sphere.hpp"
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

Sphere::Sphere() :
	Shape(),
	r_{ 1 },
	center_{0.0f, 0.0f, 0.0f}{}

Sphere::Sphere(float r) :
	Shape(),
	r_{ r },
	center_{ 0.0f, 0.0f, 0.0f }{}

Sphere::Sphere(float r , glm::vec3 center) :
	Shape(),
	r_{ r },
	center_ { center }{}

Sphere::Sphere(float r , glm::vec3 center, std::string name, Color color):
	Shape(name, color),
	r_{ r },
	center_{ center }{}

float Sphere::area() const{
	return abs(4 * M_PI * std::pow(r_, 2));
};

float Sphere::volumen() const{
	return abs((4.0f / 3.0f) * M_PI* std::pow(r_, 3));
};

