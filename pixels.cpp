#include "pixels.h"
#include<cstdlib>
#include<iostream>

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
    std::cout << "created pixels calculator" << std::endl;

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
    std::cout << "changing lightness in pixel calculator" << std::endl;
    // If the 'a' parameter is the same as before we return the value from the hashset
    if(this->a_lights == a)
    {
        std::cout << "the \'a\' param is the same, returning from hashset" << std::endl;
        return this->lights[color];
    }
    else // if the 'a' parameter is different, we recalculate the 255 color values and return
    {
        std::cout <<"lightness factor:" <<a << std::endl;
        this->a_lights = a;

        // do the calculations
        this->fillLightsHashset(a);

        // return a value from the newly-calculated hashset
        return this->lights[color];
    }
}

void Pixels::fillLightsHashset(double a)
{
    std::cout << "filling hashset" << std::endl;
    double xa = 127.5 + a;
    double ya = 255 - xa;
    for(int i = 0; i <= 255; i++)// jakby było uint8_t, to na koniec ostatniej iteracji zaczyna od zera
    {
        std::cout << (int)i << " ";
        if (xa == 0)// warunki brzegowe
        {
            this->lights[i] = 255;
        }
        else if (ya == 0)
        {
            this->lights[i] = 0;
        }

        else if (i == xa) // jeśli kolor jest w punkcie A
        {
            this->lights[i] = ya;
        }

        else if(i < xa) // obliczanie prostej AO
        {
            this->lights[i] = static_cast<uint8_t>((ya/xa) * i);
        }
        else if(i > xa) // obliczanie prostej AS
        {
            this->lights[i] = static_cast<uint8_t>(((ya-255)/(xa-255))*(i-255)+255);
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









