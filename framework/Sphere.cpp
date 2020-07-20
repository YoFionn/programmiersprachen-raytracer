#include "Sphere.hpp"
#include <math.h>
#include <glm/glm.hpp >
#include <glm/gtx/intersect.hpp>


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

HitPoint Sphere::intersect(Ray const& r) const {
	float default_distance{ 1.0f };
	bool hitpoint_check{glm::intersectRaySphere(r.origin, glm::normalize(r.direction),
						center_, std::pow(r_, 2),
						default_distance)
	};
	HitPoint tmp{		hitpoint_check, 
						default_distance,
						name_, 
						color_, 
						r.origin + (default_distance * glm::normalize(r.direction)), 
						glm::normalize(r.direction)
	};
	return tmp;
}

std::ostream& Sphere::print(std::ostream& os) const{
	Shape::print(os);
	os << "Objekt-typ Kreis" << std::endl;
	os << "Radius" << r_ << std::endl;
	os << "Oberflächeninhalt: " << area() << std::endl;
	os << "Volumen: " << volumen() << std::endl;
	return os;
}


