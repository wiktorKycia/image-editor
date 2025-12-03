#include "filter.h"
#include <cstdlib>

Filter::Filter()
{
    size = 1;
    factors = nullptr;
}

Filter::Filter(unsigned int _size)
{
    this->size = _size;
}

Filter::Filter(int8_t **factors)
{
    this->factors = factors;
}

Filter::~Filter()
{
    size = 0;
    delete factors;
}

void Filter::allocate()
{
    unsigned int _size = 2*(this->size)+1;
    this->factors = new int8_t*[_size];
    for(unsigned int i = 0; i < _size; i++)
    {
        this->factors[i] = new int8_t[_size];
        for(unsigned int j = 0; j < _size; j++)
        {
            this->factors[i][j] = 0;
        }
    }
    this->set_factor(0,0,1);
}


int8_t Filter::get_factor(int posx, int posy)
{
    int x = posx + this->size;
    int y = posy + this->size;

    return factors[y][x];
}

void Filter::set_factor(int posx, int posy, int8_t new_value)
{
    int x = posx + this->size;
    int y = posy + this->size;

    factors[y][x] = new_value;
}

