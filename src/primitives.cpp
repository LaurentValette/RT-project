#include "primitives.hpp"

Primitive::Primitive(const Material& material): m_material(material)
{
}

Sphere::Sphere(const Material& material, const glm::vec3& center, const float radius):
	Primitive(material), m_center(center), m_radius(radius)
{
}

Cube::Cube(const Material& material, const glm::vec3& origin, const glm::vec3& width, const glm::vec3& length, const glm::vec3& height):
	Primitive(material), m_origin(origin), m_width(width), m_length(length), m_height(height)
{
}

Triangle::Triangle(const Material& material, const glm::vec3& a, const glm::vec3& b, const glm::vec3& c):
	Primitive(material), m_a(a), m_b(b), m_c(c)
{
}

Ray::Ray(const glm::vec3& origin, const glm::vec3& direction): m_origin(origin), m_direction(direction)
{
}

glm::vec3& Ray::getOrigin()
{
	return m_origin;
}

glm::vec3& Ray::getDirection()
{
	return m_direction;
}

Material::Material(const glm::vec3& color, const bool isLight): m_color(color), m_light(isLight)
{
}

glm::vec3& Material::getColor()
{
	return m_color;
}

bool Material::isLight() const
{
	return m_light;
}