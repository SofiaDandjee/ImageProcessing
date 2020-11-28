//
// Created by Sofia on 06/12/2019.
//

#include "WriterCImg.h"

#include <cassert>

using namespace cimg_library;
using namespace std;

WriterCImg::WriterCImg() {}

WriterCImg::~WriterCImg () {}

void WriterCImg::saveRGBImage (const RGBImage& image, string title) const {
    size_t height = image.size();
    size_t width = image[0].size();
    size_t spectrum = image[0][0].size();

    assert(height > 0);
    assert(width > 0);
    assert (spectrum > 0);

    CImg <int> cImg (height, width, 1, spectrum);

    for (size_t i (0); i < height; ++i) {
        for (size_t j (0); j < width ; ++j) {
            for (size_t k(0); k < spectrum; ++k) {
                cImg(i,j,0,k) = image[i][j][k];
            }
        }
    }

    int n = title.length();
    char titleInChar [n + 1];
    strcpy(titleInChar , title.c_str());
    cImg.save(titleInChar);
}

void WriterCImg::saveGSImage (const Channel& image, string title) const {
    size_t height = image.size();
    size_t width = image[0].size();

    assert(height > 0);
    assert(width > 0);

    CImg <int> cImg (height, width);

    for (size_t i (0); i < height; ++i) {
        for (size_t j (0); j < width ; ++j) {
                cImg(i,j) = image[i][j];
        }
    }

    int n = title.length();
    char titleInChar [n + 1];
    strcpy(titleInChar , title.c_str());
    cImg.save(titleInChar);
}

void WriterCImg::saveFFTImage (const vector<vector<double>>& image, string title) const {
    size_t height = image.size();
    size_t width = image[0].size();

    assert(height > 0);
    assert(width > 0);

    CImg <int> cImg (height, width);

    for (size_t i (0); i < height; ++i) {
        for (size_t j (0); j < width ; ++j) {
            cImg(i,j) = image[i][j];
        }
    }

    int n = title.length();
    char titleInChar [n + 1];
    strcpy(titleInChar , title.c_str());
    cImg.save(titleInChar);
}

void WriterCImg::saveRGBImage1(const Channel &red, const Channel &green, const Channel &blue, std::string title) const {
    size_t height = red.size();
    size_t width = red[0].size();
    size_t spectrum = 3;

    assert(height > 0);
    assert(width > 0);
    assert(red.size() == green.size());
    assert(red.size() == blue.size());
    assert(blue.size() == green.size());
    assert(red[0].size() == green[0].size());
    assert(red[0].size() == blue[0].size());
    assert(blue[0].size() == green[0].size());

    CImg <int> cImg (height, width, 1, spectrum);

    for (size_t i (0); i < height; ++i) {
        for (size_t j (0); j < width ; ++j) {
            for (size_t k(0); k < spectrum; ++k) {
                if (k == 0) {
                    cImg(i,j,0,k) = red[i][j];
                } else if (k == 1) {
                    cImg(i,j,0,k) = green[i][j];
                } else if (k == 2) {
                    cImg(i,j,0,k) = blue[i][j];
                }

            }
        }
    }
    int n = title.length();
    char titleInChar [n + 1];
    strcpy(titleInChar , title.c_str());
    cImg.save(titleInChar);
}