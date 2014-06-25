#include "primitives.hpp"

Primitive::Primitive(const Material& material): m_material(material)
{
}

Sphere::Sphere(const Material& material, const glm::vec3& center, const float radius):
	Primitive(material), m_center(center), m_radius(radius)
{
}

bool Sphere::intersect(const Ray& ray, glm::vec3* intersection) const
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

bool Cube::intersect(const Ray& ray, glm::vec3* intersection) const
{
	return false;
}

Triangle::Triangle(const Material& material, const glm::vec3& a, const glm::vec3& b, const glm::vec3& c):
	Primitive(material), m_a(a), m_b(b), m_c(c)
{
}

bool Triangle::intersect(const Ray& ray, glm::vec3* intersection) const
{
	// We solve the equation: p + lambda d = alpha a + beta b + (1 - alpha - beta) c
	glm::vec3 v1, v2, v3, b;
	v1 = ray.getDirection();
	v2 = -m_a + m_c;
	v3 = -m_b + m_c;
	b = -ray.getOrigin() + m_c;

	float det = glm::determinant(glm::mat3(ray.getDirection(), -m_a + m_c, -m_b + m_c));
	if (det >= -0.00001f && det <= 0.00001f) {
		// Det = 0: The line is parallel to the plane
		return false;
	}  else {
		// Det != 0: The line has an intersection with the plane, apply Cramer's rule
		float alpha = glm::determinant(glm::mat3(v1, b, v3)) / det;
		float beta = glm::determinant(glm::mat3(v1, v2, b)) / det;

		if (alpha >= 0.f && beta >= 0.f && alpha + beta <= 1.f) {
			// The intersection is in the triangle
			if (intersection) {
				*intersection = alpha * m_a + beta * m_b + (1.f - alpha - beta) * m_c;
			}
			return true;
		} else {
			return false;
		}
	}
}

Ray::Ray(const glm::vec3& origin, const glm::vec3& direction): m_origin(origin), m_direction(direction)
{
}

const glm::vec3& Ray::getOrigin() const
{
	return m_origin;
}

const glm::vec3& Ray::getDirection() const
{
	return m_direction;
}

Material::Material(const glm::vec3& color, const bool isLight): m_color(color), m_light(isLight)
{
}

const glm::vec3& Material::getColor() const
{
	return m_color;
}

bool Material::isLight() const
{
	return m_light;
}

void project(const Ray& ray, const glm::vec3& point, glm::vec3* projection)
{
	glm::vec3 normalizedDirection = glm::normalize(ray.getDirection());
	*projection = glm::dot(point - ray.getOrigin(), normalizedDirection) * normalizedDirection + ray.getOrigin();
}
