#include "filter.h"
#include <cstdlib>

Filter::Filter()
{
    size = 1;
    this->factors = new int8_t*[size];
    for(unsigned int i = 0; i < size; i++)
    {
        this->factors[i] = new int8_t[size];
        for(unsigned int j = 0; j < size; j++)
        {
            this->factors[i][j] = 0;
        }
    }
    this->set_factor(0,0,1);
}

Filter::Filter(unsigned int _size)
{
    this->size = _size;

    unsigned int arraySize = 2*(this->size)+1;
    this->factors = new int8_t*[arraySize];
    for(unsigned int i = 0; i < arraySize; i++)
    {
        this->factors[i] = new int8_t[arraySize];
        for(unsigned int j = 0; j < arraySize; j++)
        {
            this->factors[i][j] = 0;
        }
    }
    this->set_factor(0,0,1);
}

Filter::Filter(unsigned int _size, int8_t **_factors)
{
    this->size = _size;
    unsigned int arraySize = 2*(this->size)+1;

    this->factors = new int8_t*[arraySize];
    for(unsigned int i = 0; i < arraySize; i++)
    {
        this->factors[i] = new int8_t[arraySize];
        for(unsigned int j = 0; j < arraySize; j++)
        {
            this->factors[i][j] = _factors[i][j];
        }
    }
}

Filter::~Filter()
{
    size = 0;
    delete factors;
}


int8_t Filter::get_factor(int posx, int posy)
{
    int x = posx + this->size;
    int y = posy + this->size;

    return factors[y][x];
}

void Filter::set_factor(int posx, int posy, const int8_t &new_value)
{
    int x = posx + this->size;
    int y = posy + this->size;

    unsigned int arraySize = 2 * size + 1;

    if (x < 0 || y < 0 || x >= arraySize || y >= arraySize)
        return;
    else
        this->factors[y][x] = new_value;
}

