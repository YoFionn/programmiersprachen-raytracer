#include "Box.hpp"
#include <cmath>
#include <iostream>

Box::Box() :
	min_{0.0f, 0.0f, 0.0f},
	max_{ 1.0f, 1.0f, 1.0f }{}

Box::Box(glm::vec3 min, glm::vec3 max) :
	min_{ min },
	max_{ max }{}

float Box::area() const{
	return abs(6 * (max_.x - min_.x));
}

float Box::volumen() const {
	return abs(pow((max_.x - min_.x), 3));
}