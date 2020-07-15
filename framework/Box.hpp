#include<glm/vec3.hpp>

class Box : public Shape {
public:
	Box();
	Box(glm::vec3 min, glm::vec3 max);
	Box(glm::vec3 min, glm::vec3 max, std::string name, Color color);
	float area() const override;
	float volumen() const override;

private:
	glm::vec3 min_;
	glm::vec3 max_;
};