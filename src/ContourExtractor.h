//
// Created by Sofia on 06/01/2020.
//

#ifndef IMAGE_PROCESSING_CONTOUREXTRACTOR_H
#define IMAGE_PROCESSING_CONTOUREXTRACTOR_H

class ContourExtractor {
public:
    virtual Channel detectVerticalEdges (const Channel& image) const = 0;
    virtual Channel detectHorizontalEdges (const Channel& image) const = 0;
    virtual Channel detectAllEdges (const Channel& image) const = 0;
};
#endif //IMAGE_PROCESSING_CONTOUREXTRACTOR_H
