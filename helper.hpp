#ifndef HELPER_HPP
#define HELPER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Helper {
public:
    Vector2f Interpolate(Vector2f pointA, Vector2f pointB, float factor);
};

#endif //HELPER_HPP