//
// Created by Sofia on 08/12/2019.
//

#ifndef IMAGE_PROCESSING_FFT_H
#define IMAGE_PROCESSING_FFT_H

#include <vector>
#include <complex>
#include "ReaderCImg.h"

//! Typedef
/*! A Complex represents a complex of double */
typedef std::complex<double> Complex;

//! Typedef
/*! A ComplexVector represents a 2D vector of Complex */
typedef std::vector<std::vector<Complex>> ComplexVector;

void DiscreteFourierTransform2D(ComplexVector& FFT2D);

//! Calculates the modulus/amplitude of a 2D Fourier Transform
/*!
 *
 * @param FFT, a ComplexVector
 * @return a 2D vector of double
 */
std::vector<std::vector<double>> FFTModulus(const ComplexVector& FFT);

//! Converts an Channel into its Complex counterpart
/*!
 * Used to calculate the FFT
 * @param image a Channel
 * @return a ComplexVector
 */
ComplexVector convertImageInComplex(const Channel& image);

//! Converts a ComplexVector into its int counterpart
/*!
 * Used to display the inverse Fourier Transform with the CImg library
 * @param image a ComplexVector
 * @return a Channel
 */
Channel convertComplexInInt (const ComplexVector& image);

//! Computes the FFT of an image in-place using the Cooley-Tukey algorithm if the dimensions are even, if not uses the naive algorithm
/*!
 *
 * @param image a ComplexVector&
 */
void FFT (ComplexVector& image);

//! Computes the IFFT of an image, in-place
/*!
 *
 * @param fft a ComplexVector&
 */
void IFFT (ComplexVector& fft);

//! Computes the conjugate of a ComplexVector
/*!
 *
 * @param fft a ComplexVector&
 */
void conjugate (ComplexVector& fft);

#endif //IMAGE_PROCESSING_FFT_H
