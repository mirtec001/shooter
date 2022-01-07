#include "helper.hpp"


Vector2f Helper::Interpolate(Vector2f pointA, Vector2f pointB, float factor) {
    

    // Vector2f maths = pointA + (pointB - pointA) * factor;
    Vector2f maths = pointA + (pointB - pointA) * factor;

    return maths;
}