/**
 * @file
 *  This file is part of PUMGen
 *
 *  For conditions of distribution and use, please see the copyright
 *  notice in the file 'COPYING' at the root directory of this package
 *  and the copyright notice at https://github.com/SeisSol/PUMGen
 *
 * @copyright 2018 LMU-TUM 
 * @author Thomas Ulrich
 */
#ifndef ANALYSISATTRIBUTES_H
#define ANALYSISATTRIBUTES_H

#include <unordered_map>
#include "tinyxml2/tinyxml2.h"
#include <string>
#include <list>
#include <vector>
#include "utils/logger.h"
#include "split.h"



using namespace tinyxml2;

struct faceBoundary {
  faceBoundary(int faceID, int bcType) : faceID(faceID), bcType(bcType) {};
  int faceID;
  int bcType;
};

class AnalysisAttributes {
  public:
    std::vector<faceBoundary> faceBound;
    AnalysisAttributes(const char* xmlFilename, int numFaces);
  private:
    XMLDocument doc;
    void readXmlFile(const char* xmlFilename);
    void set_BoundaryConditions();
};

#endif
