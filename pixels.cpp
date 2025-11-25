#include "pixels.h"
#include<cstdlib>

Pixels::Pixels()
{
    this->negatives = new uint8_t[256];
    this->lights = new uint8_t[256];
    this->contrasts = new uint8_t[256];

    for (int i = 0; i <= 255; i++)
    {
        this->negatives[i] = 255-i;
        this->lights[i] = 0;
        this->contrasts[i] = 0;
    }
}

Pixels::~Pixels()
{
    delete[] this->negatives;
    delete[] this->lights;
    delete[] this->contrasts;
}

uint8_t Pixels::reverseColor(uint8_t color)
{
    return this->negatives[color];
}

uint8_t Pixels::changeLightness(uint8_t color, double a)
{
    // If the 'a' parameter is the same as before we return the value from the hashset
    if(this->a_lights == a)
    {
        return this->lights[color];
    }
    else // if the 'a' parameter is different, we recalculate the 255 color values and return
    {
        this->a_lights = a;

        // do the calculations
        this->fillLightsHashset(a);

        // return a value from the newly-calculated hashset
        return this->lights[color];
    }
}

void Pixels::fillLightsHashset(double a)
{
    for(uint8_t i = 0; i <= 255; i++)
    {
        double xa = 127.5 + a;
        double ya = 255 - xa;

        if (xa == 0)// warunki brzegowe
        {
            this->lights[i] = 255;
            continue;
        }
        if (ya == 0)
        {
            this->lights[i] = 0;
            continue;
        }

        if (i == xa) // jeśli kolor jest w punkcie A
        {
            this->lights[i] = ya;
            continue;
        }

        if(i < xa) // obliczanie prostej AO
        {
            this->lights[i] = (ya/xa) * i;
            continue;
        }
        if(i > xa) // obliczanie prostej AS
        {
            this->lights[i] = ((ya-255)/(xa-255))*(i-255)+255;
            continue;
        }
    }
}

uint8_t Pixels::changeContrast(uint8_t color, double a)
{
    // If the 'a' parameter is the same as before we return the value from the hashset
    if(this->a_contrasts == a)
    {
        return this->contrasts[color];
    }
    else // if the 'a' parameter is different, we recalculate the 255 color values and return
    {
        this->a_contrasts = a;

        //! do the calculations

        return this->contrasts[color];
    }
}









