#ifndef PORTABLEPIXMAP_H
#define PORTABLEPIXMAP_H


#include<string>
#include<cstdint>

using namespace std;

class PortablePixMap
{
    static const int numberOfColors = {3};
    unsigned int sizex, sizey;
    uint8_t ***pixels;

    void allocate_pixels();

    void readAsciiFile(string fileName);
    void readBinaryFile(string fileName);

public:
    PortablePixMap();
    PortablePixMap(unsigned int _sizex, unsigned int _sizey);
    PortablePixMap(const PortablePixMap &obj);
    ~PortablePixMap();

    uint8_t getPixel(unsigned int x, unsigned int y, unsigned int color) const;

    void readFile(string fileName);

    void writeFilePPM(string fileName);
    void writeFilePGM(string fileName);
    void writeFilePBM(string fileName);

    void writeBinaryFilePPM(string fileName);
    void writeBinaryFilePGM(string fileName);
    void writeBinaryFilePBM(string fileName);

    void convert_to_negative();
    void enlighten(double a);
    void darken(double a);
    void contrast(double a);
    void decontrast(double a);
};

#endif // PORTABLEPIXMAP_H
