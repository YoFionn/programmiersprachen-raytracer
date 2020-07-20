#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <cmath>
#include <iostream>
#include <glm/vec3.hpp>
#include "color.hpp"
#include <string>

class Shape {
public:
	Shape();
	Shape(std::string name, Color color);
	virtual float area() const = 0;
	virtual float volumen() const = 0;
	virtual std::ostream& print(std::ostream& os) const;
	~Shape();

protected:
	std::string name_;
	Color color_;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif