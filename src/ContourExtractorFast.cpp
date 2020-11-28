//
// Created by Sofia on 06/01/2020.
//

#include "ContourExtractorFast.h"

#include "FFT.h"

Channel ContourExtractorFast::detectVerticalEdges (const Channel& image) const override {
    Channel filter = {{-1, -2, -1},{0, 0, 0},{1, 2, 1}}; //Sobel filter
    ComplexVector fftFilter = convertImageInComplex(filter);
    FFT(fftFilter);
    ComplexVector fftImage = convertImageInComplex(image);
    FFT(fftImage);

}
Channel ContourExtractorFast::detectHorizontalEdges (const Channel& image) const override {
    vector<vector<int>> filter = {{-1, 0, 1},{-2, 0, 2},{-1, 0, 1}}; //Sobel filter
}
Channel ContourExtractorFast::detectAllEdges (const Channel& image) const override {

}
