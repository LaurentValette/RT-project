#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include "common.h"

//enum prim_type {SPHERE, CUBE, TRIANGLE};

class Primitive
{
public:
	Primitive();
	Primitive(glm::vec4 color, bool isLight);

	glm::vec4 getColor() const;
	void setColor(const glm::vec4 color);
	bool isLight() const;
	void setLight(const bool isLight);

private:
	glm::vec4 m_color;
	bool m_light;
}

#endif