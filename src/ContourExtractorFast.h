//
// Created by Sofia on 06/01/2020.
//

#ifndef IMAGE_PROCESSING_CONTOUREXTRACTORFAST_H
#define IMAGE_PROCESSING_CONTOUREXTRACTORFAST_H

#include "ContourExtractor.h"

class ContourExtractorFast : public ContourExtractor {

    Channel detectVerticalEdges (const Channel& image) const override;
    Channel detectHorizontalEdges (const Channel& image) const override;
    Channel detectAllEdges (const Channel& image) const override;

};


#endif //IMAGE_PROCESSING_CONTOUREXTRACTORFAST_H
