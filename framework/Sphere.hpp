#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <iostream>
#include <cmath>
#include "shape.cpp"
#include "color.hpp"
#include "ray.hpp"
#include "hitpoint.hpp"
#include <string>

class Sphere : public Shape {
public:

	Sphere();
	Sphere(float r);
	Sphere(float r, glm::vec3 center);
	Sphere(float r, glm::vec3 center, std::string name, Color color);
	float area() const override;
	float volumen() const override;
	HitPoint intersect(Ray const& r) const;
	std::ostream& print(std::ostream& os) const override;


private:
	glm::vec3 center_;
	float r_{1};
};

#endif