#ifndef PIXELS_H
#define PIXELS_H
#pragma once
#include <cstdint>

extern const double e;

class Pixels
{
private:
    // the 'a' parameters of the functions, used to determine, whether the arrays store values for the correct color scale or not
    double a_lights;
    double a_constasts;

    // hashsets for storing values of the functions
    uint8_t negatives[255];
    uint8_t lights[255];
    uint8_t contrasts[255];

public:
    Pixels();
    uint8_t reverseColor(uint8_t color);
    uint8_t changeLightness(uint8_t color, double a);
    uint8_t changeContrast(uint8_t color, double a);
};

#endif // PIXELS_H
