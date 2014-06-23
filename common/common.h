#ifndef COMMON_H
#define COMMON_H

#include <cstdlib>
#include <iostream>
#include <glm/glm.hpp>

inline std::ostream &operator<< (std::ostream& out, const glm::vec3& vec) {
    out << "{" << vec.x << " " << vec.y << " "<< vec.z << "}";
    return out;
}

#endif