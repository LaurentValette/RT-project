#include "primitives.hpp"

Primitive::Primitive(): m_color(0.f), m_light(false)
{
}

Primitive::Primitive(glm::vec4 color, bool isLight): m_color(color), m_light(isLight)
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