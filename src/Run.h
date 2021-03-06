//
// Created by Sofia on 11/12/2019.
//

#ifndef IMAGE_PROCESSING_RUN_H
#define IMAGE_PROCESSING_RUN_H

#include <string>

#include "ReaderCImg.h"
#include "WriterCImg.h"
#include "ContourExtractorSlow.h"
#include "Histogram.h"
#include "HistogramWriter.h"
#include "FFT.h"

//! Run class
/*!
 * To run the main program
 */

class Run {
private:
    Reader* r;
    Writer* w;
    ContourExtractorSlow* c;
    Histogram h;

public:
    //! A default constructor
    Run();

    //! A destructor
    ~Run();

    //! Asks the user to choose an image to process
    /*!
     *
     * @return a string, the filepath of the image
     */
    std::string chooseImagePath();

    //! Asks the user if the image is in RGB or greyscale (will be processed differently)
    /*!
     *
     * @return true if the image is colored, false if not
     */
    bool isColored();

    //! Asks the user if he wants to compute an histogram, compute the Fast Fourier Transform or extract contours
    /*!
     *
     * @return 1 for histograms, 2 for the contour extraction, 3 for the FFT
     */
    int askUser();

    //! Process the image according to the user's choice
    /*!
     *
     * @param filepath a string, the path of the file
     * @param color a boolean to know if the image is colored
     * @param process the user's choice of functionality
     */
    void run(int process, bool color, std::string filepath);

    //! Extract the contours of an image and saves it in a .jpeg file
    /*!
     *
     * @param image, a Channel
     */
    void extractContours(const Channel& image);

    //! Computes the FFT of an greyscale image and its inverse and saves the modulus of the FFT and the reconstruction in image files
    /*!
     *
     * @param image, a Channel
     */
    void computeFFTandIFFTGS(const Channel& image);

    //! Computes the FFT of each channel of a RGB image, reconstructs the image and saves the modulus of the FFTs and the reconstruction in image files
    /*!
     *
     * @param image, a Channel
     */
    void computeFFTandIFFTColor(std::string filepath);

    //! Computes the histogram of an image
    /*!
     *
     * @param image, a Channel
     * @param filepath, the name of the text file to store the ChannelHistogram
     */
    void computeHistogram(const Channel& image, std::string filepath);

};


#endif //IMAGE_PROCESSING_RUN_H
