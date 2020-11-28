//
// Created by Sofia on 06/12/2019.
//

#ifndef IMAGE_PROCESSING_WRITERCIMG_H
#define IMAGE_PROCESSING_WRITERCIMG_H

#include "Writer.h"

#include <vector>
#include <string>

//Include the libraries for png and jpeg images
#include "../libraries/libpng-1.6.37/png.h"
#include "../libraries/libpng-1.6.37/pnglibconf.h"
#include "../libraries/libjpeg/jpeglib.h"

#include "ReaderCImg.h"
#include "../libraries/CImg.h"

using namespace cimg_library;

//! Writer class
/*!
 * To write images in order to visualize results
 */

class WriterCImg : public Writer {

public:

    //! A default constructor
    WriterCImg();

    //! A destructor
    ~WriterCImg();

    //! Writes a colored CImg image from a 3D vector of int
    /*!
     *
     * @param image, an RGBImage
     * @return an image in the CImg<int> format
     */
    void saveRGBImage (const RGBImage& image, std::string) const override;

    //! Writes a greyscale CImg image from a 2D vector of int
    /*!
     *
     * @param image, a Channel
     * @return an image in the CImg<int> format
     */
    void saveGSImage (const Channel& image, std::string) const override;

    //! Writes a greyscale CImg image from a 2D vector of double
    /*!
     *
     * @param image, a vector<vector<double>>
     * @return an image in the CImg<double> format
     */
    void saveFFTImage (const std::vector<std::vector<double>>& image, std::string) const override;

    //! Writes a RGB CImg image from 3 Channels
    /*!
     *
     * @param red, the red Channel
     * @param green, the green Channel
     * @param blue, the blue Channel
     * @return an image in the CImg<int> format
     */
    void saveRGBImage1 (const Channel& red, const Channel& green, const Channel& blue, std::string) const override;
};


#endif //IMAGE_PROCESSING_WRITERCIMG_H
