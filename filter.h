#ifndef FILTER_H
#define FILTER_H
#include<cstdlib>

class Filter
{
    int8_t **factors;
public:
    unsigned int size;
    int8_t get_factor(int posx, int posy);
    void set_factor(int posx, int posy, const int8_t &new_value);

    Filter();
    Filter(unsigned int _size);
    Filter(unsigned int _size, int8_t **_factors);
    ~Filter();
};

#endif // FILTER_H
