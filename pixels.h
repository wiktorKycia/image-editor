#ifndef PIXELS_H
#define PIXELS_H
#pragma once
#include <cstdint>
#include <cstddef> // for NULL value

extern const double e;

class Pixels
{
private:
    // the 'a' parameters of the functions, used to determine, whether the arrays store values for the correct color scale or not
    double a_lights = NULL;
    double a_contrasts = NULL;

    // hashsets for storing values of the functions
    uint8_t *negatives;
    uint8_t *lights;
    uint8_t *contrasts;

    void fillNegativesHashset();
    void fillLightsHashset(double a);
    void fillContrastHashset(double a);

public:
    Pixels();
    ~Pixels();
    uint8_t reverseColor(uint8_t color);
    uint8_t changeLightness(uint8_t color, double a);
    uint8_t changeContrast(uint8_t color, double a);
};

#endif // PIXELS_H
