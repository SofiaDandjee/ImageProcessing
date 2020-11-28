//
// Created by Sofia on 06/01/2020.
//

#ifndef IMAGE_PROCESSING_WRITER_H
#define IMAGE_PROCESSING_WRITER_H

#include "Reader.h"

class Writer {

public:
    virtual void saveRGBImage (const RGBImage& image, std::string) const = 0;
    virtual void saveGSImage (const Channel& image, std::string) const = 0;
    virtual void saveFFTImage (const std::vector<std::vector<double>>& image, std::string) const = 0;
    virtual void saveRGBImage1 (const Channel& red, const Channel& green, const Channel& blue, std::string) const = 0;
};


#endif //IMAGE_PROCESSING_WRITER_H
