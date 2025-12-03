#ifndef PORTABLEPIXMAP_H
#define PORTABLEPIXMAP_H


#include<string>
#include<cstdint>
#include<QImage>
#include "pixels.h"
#include "filter.h"

using namespace std;

class PortablePixMap
{
    static const int numberOfColors = {3};
    unsigned int sizex, sizey;
    uint8_t ***pixels;
    uint8_t ***pixelsCopy;

    Filter *filter;
    Pixels *pixelCalculator;

    void allocate_pixels();
    void allocate_filter();

    void readAsciiFile(string fileName);
    void readBinaryFile(string fileName);

public:
    double currentLightnessFactor={0};
    double currentContrastFactor={0};

    PortablePixMap();
    PortablePixMap(unsigned int _sizex, unsigned int _sizey, unsigned int filterSize = 1);
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
    void changeLightness(double a);
    void changeContrast(double a);

    QImage toQImage() const;
};

#endif // PORTABLEPIXMAP_H
