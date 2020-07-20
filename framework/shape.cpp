#include<cmath>
#include<iostream>
#include "shape.hpp"
#include<glm/vec3.hpp>

Shape::Shape():
	name_{"default"},
	color_{0.0f, 0.0f, 0.0f}{}

Shape::Shape(std::string name, Color color):
	name_{name},
	color_{color}{}

std::ostream& Shape::print(std::ostream& os) const {
	os << "name: " << name_ << ", Farbe: (" << color_.r << ", " << color_.g << ", " << color_.b << ")" << std::endl;
	return os;
}

Shape::~Shape() {
	std::cout << "This is the end of: " << name_ << std::endl;
}

std::ostream& operator<<(std::ostream& os, Shape const& s) {
	return s.print(os);
}

