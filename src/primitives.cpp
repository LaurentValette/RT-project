#include "primitives.hpp"

Primitive::Primitive(const glm::vec4 color, const bool isLight): m_color(color), m_light(isLight)
{
}

glm::vec4 Primitive::getColor() const
{
	return m_color;
}

void Primitive::setColor(const glm::vec4 color) 
{
	m_color = color;
}

bool Primitive::isLight() const
{
	return m_light;
}

void Primitive::setLight(const bool isLight)
{
	m_light = isLight;
}

Sphere::Sphere(const glm::vec4 color, const bool isLight, const glm::vec3 center, const float radius):
			Primitive(color, isLight), m_center(center), m_radius(radius)
{
}

Cube::Cube(const glm::vec4 color, const bool isLight, const glm::vec3 origin, const glm::vec3 width, const glm::vec3 length, const glm::vec3 height):
			Primitive(color, isLight), m_origin(origin), m_width(width), m_length(length), m_height(height)
{
}

Triangle::Triangle(const glm::vec4 color, const bool isLight, const glm::vec3 a, const glm::vec3 b, const glm::vec3 c): Primitive(color, isLight), m_a(a); m_b(b), m_c(c)
{
}

Ray::Ray(const glm::vec3 origin, const glm::vec3 direction): m_origin(origin), m_direction(direction)
{
}

glm::vec3 Ray::getOrigin() const
{
	return m_origin;
}

glm::vec3 Ray::getDirection() const
{
	return m_direction;
}