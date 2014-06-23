#include "primitives.hpp"

Primitive::Primitive(const Material& material): m_material(material)
{
}

Sphere::Sphere(const Material& material, const glm::vec3& center, const float radius):
	Primitive(material), m_center(center), m_radius(radius)
{
}

bool Sphere::intersect(Ray& ray, glm::vec3* intersection) const
{
	glm::vec3 projectedCenter;
	project(ray, m_center, &projectedCenter);
	float normProjCent = glm::length(projectedCenter - m_center);
	if (normProjCent > m_radius) {
		// The projection is outside of the sphere
		return false;
	} else {
		if (intersection) {
			// c is the length from the projectedCenter to the intersection
			float c = sqrt(m_radius * m_radius - normProjCent * normProjCent);
			// lambda is how much we need to move on the line to reach the intersection
			float lambda = glm::length(projectedCenter - ray.getOrigin()) - c;
			*intersection = ray.getOrigin() + lambda * glm::normalize(ray.getDirection());
		}
		return true;
	}
}

Cube::Cube(const Material& material, const glm::vec3& origin, const glm::vec3& width, const glm::vec3& length, const glm::vec3& height):
	Primitive(material), m_origin(origin), m_width(width), m_length(length), m_height(height)
{
}

bool Cube::intersect(Ray& ray, glm::vec3* intersection) const
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

void project(Ray& ray, const glm::vec3& point, glm::vec3* projection)
{
	glm::vec3 normalizedDirection = glm::normalize(ray.getDirection());
	*projection = glm::dot(point - ray.getOrigin(), normalizedDirection) * normalizedDirection + ray.getOrigin();
}
