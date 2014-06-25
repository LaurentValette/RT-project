#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include "common.h"

class Ray
{
public:
	Ray(const glm::vec3& origin, const glm::vec3& direction);
	const glm::vec3& getOrigin() const;
	const glm::vec3& getDirection() const;

private:
	glm::vec3 m_origin;
	glm::vec3 m_direction;
};

class Material
{
public:
	Material(const glm::vec3& color, const bool isLight);
	const glm::vec3& getColor() const;
	bool isLight() const;

private:
	glm::vec3 m_color;
	bool m_light;
	// diffuse, specular, shininess
};

//enum prim_type {SPHERE, CUBE, TRIANGLE};

class Primitive
{
public:
	Primitive(const Material& material);

	virtual bool intersect(const Ray& ray, glm::vec3* intersection) const = 0;

protected:
	Material m_material;
};

class Sphere: public Primitive
{
public:
	Sphere(const Material& material, const glm::vec3& center, const float radius);
	bool intersect(const Ray& ray, glm::vec3* intersection) const;

private:
	glm::vec3 m_center;
	float m_radius;
};

// Actually, Cube defines a parallelepiped
class Cube: public Primitive
{
public:
	Cube(const Material& material, const glm::vec3& origin, const glm::vec3& width, const glm::vec3& length, const glm::vec3& height);
	bool intersect(const Ray& ray, glm::vec3* intersection) const;

private:
	glm::vec3 m_origin, m_width, m_length, m_height;
};

class Triangle: public Primitive
{
public:
	Triangle(const Material& material, const glm::vec3& a, const glm::vec3& b, const glm::vec3& c);
	bool intersect(const Ray& ray, glm::vec3* intersection) const;

private:
	glm::vec3 m_a, m_b, m_c;
};

void project(const Ray& ray, const glm::vec3& point, glm::vec3* projection);

#endif