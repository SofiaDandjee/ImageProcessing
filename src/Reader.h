//
// Created by Sofia on 06/01/2020.
//

#ifndef IMAGE_PROCESSING_READER_H
#define IMAGE_PROCESSING_READER_H

#include <vector>
#include <string>

//! Typedef
/*! An Image represents a 2D image of pixels (int)
 * with 3 channels (RGB) */
typedef std::vector <std::vector<std::vector<int>>> RGBImage;

//! Typedef
/*! A Channel represents a 2D image of pixels (int)
 * in a red/green/blue/grey spectrum */
typedef std::vector<std::vector<int>> Channel;

class Reader {

public:
    virtual RGBImage loadRGBImage(std::string filename) const = 0;

    virtual Channel loadGSImage(std::string filename) const = 0;

    virtual Channel extractRedChannel (std::string filename) const = 0;

    virtual Channel extractBlueChannel (std::string filename) const = 0;

    virtual Channel extractGreenChannel (std::string filename) const = 0;

    virtual Channel convertColoredToGS (std::string filename) const = 0;
};


#endif //IMAGE_PROCESSING_READER_H
