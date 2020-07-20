#ifndef HIT_POINT_HPP
#define HIT_POINT_HPP

#include <glm/glm.hpp >
#include <glm/gtx/intersect.hpp>
#include <string>
#include "color.hpp"

struct HitPoint {
	bool intersect{ false };
	float dist {0.0f};
	std::string name{ "" };
	Color color{ {1.0f},{1.0f},{1.0f} };
	glm::vec3 schnittstelle { 0.0f, 0.0f, 0.0f };
	glm::vec3 directions { 0.0f, 0.0f, 0.0f };
};

#endif