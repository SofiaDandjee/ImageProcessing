//
// Created by Sofia on 04/12/2019.
//

#ifndef IMAGE_PROCESSING_CONTOUREXTRACTORSLOW_H
#define IMAGE_PROCESSING_CONTOUREXTRACTORSLOW_H

#include "ReaderCImg.h"

#include "ContourExtractor.h"

#include <vector>

//! ContourExtractor  class
/*!
 * Implements the Sobel filter to extract contours of an image
 */

class ContourExtractorSlow : public ContourExtractor {

public:
    //! A default constructor
    ContourExtractorSlow();

    //! A destructor
    ~ContourExtractorSlow();

    //! Adds a padding of 0-values all around the image, prepares the image for convolution
    /*!
     *
     * @param image a Channel, the image to be padded
     * @return a Channel, the padded image
     */
    Channel preprocess (const Channel& image) const;

    //! Extracts vertical contours of an image
    /*!
     *
     * @param image a Channel, the input image
     * @return a Channel, the output image representing the vertical contours of the input
     */
    Channel detectVerticalEdges (const Channel& image) const override;

    //! Extracts horizontal contours of an image
    /*!
     *
     * @param image a Channel, the input image
     * @return a Channel, the output image representing the horizontal contours of the input
     */
    Channel detectHorizontalEdges (const Channel& image) const override;

    //! Applies convolution between an image and a filter
    /*!
     *
     * @param filter, a 2d vector of double
     * @param image, the image to be convoluted with the filter, a Channel
     * @return a Channel, the image convoluted
     */
    Channel convolution (const Channel& image, Channel filter) const;

    //! Extracts contours of an image
    /*!
     *
     * @param image a Channel, the input image
     * @return a Channel, the output image representing the contours of the input
     */
    Channel detectAllEdges (const Channel& image) const override;
};


#endif //IMAGE_PROCESSING_CONTOUREXTRACTORSLOW_H
