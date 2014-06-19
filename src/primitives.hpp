#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include "common.h"

//enum prim_type {SPHERE, CUBE, TRIANGLE};

class Primitive
{
public:
	Primitive(const glm::vec4 color, const bool isLight);

	glm::vec4 getColor() const;
	void setColor(const glm::vec4 color);
	bool isLight() const;
	void setLight(const bool isLight);
	float intersect(const Ray ray) const;

protected:
	glm::vec4 m_color;
	bool m_light;
}

class Sphere: public Primitive
{
public:
	Sphere(const glm::vec4 color, const bool isLight, const glm::vec3 center, const float radius);

private:
	glm::vec3 m_center;
	float m_radius;
}

// Actually, Cube defines a parallelepiped
class Cube: public Primitive
{
public:
	Cube(const glm::vec4 color, const bool isLight, const glm::vec3 origin, const glm::vec3 width, const glm::vec3 length, const glm::vec3 height);

private:
	glm::vec3 m_origin, m_width, m_length, m_height;
}

class Triangle: public Primitive
{
public:
	Triangle(const glm::vec4 color, const bool isLight, const glm::vec3 a, const glm::vec3 b, const glm::vec3 c);

private:
	glm::vec3 m_a, m_b, m_c;
}

class Ray
{
public:
	Ray(const glm::vec3 origin, const glm::vec3 direction);
	glm::vec3 getOrigin() const;
	glm::vec3 getDirection() const;

private:
	glm::vec3 m_origin;
	glm::vec3 m_direction;
}

#endif