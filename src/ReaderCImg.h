//
// Created by Sofia on 29/11/2019.
//


#ifndef IMAGE_SOUND_PROCESSING_READER_H
#define IMAGE_SOUND_PROCESSING_READER_H


#include "Reader.h"

//Include the libraries for png and jpeg images
#include "../libraries/libpng-1.6.37/png.h"
#include "../libraries/libpng-1.6.37/pnglibconf.h"
#include "../libraries/libjpeg/jpeglib.h"

//Comment the defines if you're on Linux
#define cimg_use_png 1
#define cimg_use_jpeg 1

#include "../libraries/CImg.h"
using namespace cimg_library;



//! Reader class
/*!
 * To load and manipulate PNG/JPEG images
 */

class ReaderCImg : public Reader {

public:

    //! A default constructor
    ReaderCImg();

    //! A destructor
    ~ReaderCImg();

    //! Loads a CImg image
    /*!
     *
     * @param filename a string, the path of the file
     * @return an image in the CImg<int> format
     */
    CImg <int> loadCImg(std::string filename) const;

    //! Loads an RGB image into a 1 or 3-channelled 2D vector of int
    /*!
     *
     * @param filename a string, the path of the file
     * @return an Image
     */
     RGBImage loadRGBImage(std::string filename) const override;

    //! Loads a greyscale image into a 2D vector of int
    /*!
     *
     * @param filename a string, the path of the file
     * @return a Channel
     */
    Channel loadGSImage(std::string filename) const override;

    //! Extracts the red channel of an image
    /*!
     *
     * @param filename a string, the path of the file
     * @return a Channel
     */
    Channel extractRedChannel (std::string filename) const override;

    //! Extracts the green channel of an image
    /*!
     *
     * @param filename a string, the path of the file
     * @return a Channel
     */
    Channel extractBlueChannel (std::string filename) const override;

    //! Extracts the blue channel of an image
    /*!
     *
     * @param filename a string, the path of the file
     * @return a Channel
     */
    Channel extractGreenChannel (std::string filename) const override;

    //! Converts a CImg type into 1 or 3-channelled 2D image
    /*!
     *
     * @param cImg, to be converted
     * @return an Image
     */
    RGBImage convertImage (CImg <int> cImg) const;

    //! Converts a CImg type into a channel
    /*!
     *
     * @param cImg, to be converted
     * @return a Channel
     */
    Channel convertChannel (CImg <int> cImg) const;

    //! Loads an RGB image as a GS image
    /*!
     *
     * @param filename, the path of the file
     * @return a Channel, the image converted to greyscale
     */
     Channel convertColoredToGS (std::string filename) const override;

};


#endif //IMAGE_SOUND_PROCESSING_READER_H
