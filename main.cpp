#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <list>
#include <map>

#include "Vector.hpp"
#include "Vector.cpp"
#include "VectorHori.hpp"
#include "VectorHori.cpp"
#include "VectorVert.hpp"
#include "VectorVert.cpp"
#include "Factory.hpp"
#include "FactoryHori.hpp"
#include "FactoryVert.hpp"

using namespace VECTOR_HORI_VERT;

typedef int EL_TYPE;

int main() {
  try {

    /* smart pointer - unique_ptr */
    std::map< std::string, std::unique_ptr<Factory<EL_TYPE>> > factoryMap;
    //factoryMap["Hori"] = std::make_unique<FactoryHori<EL_TYPE>>();    // unexpectedly make_unique() is C++14
    factoryMap["Hori"] = std::unique_ptr<Factory<EL_TYPE>>(new FactoryHori<EL_TYPE>);
    //factoryMap["Vert"] = std::make_unique<FactoryVert<EL_TYPE>>();
    factoryMap["Vert"] = std::unique_ptr<Factory<EL_TYPE>>(new FactoryVert<EL_TYPE>);

    /* smart pointer - shared_ptr */
    std::vector< std::shared_ptr<Vector<EL_TYPE>> > vectorVector;
    const std::string inputFileName = "input.txt";

    /*
    * Format of input file is:
    * Hori file1.txt 1 2 3
    * Vert file2.txt 8 9 10
    */

    std::ifstream inputFile(inputFileName.c_str(), std::ios_base::in);
    if (!inputFile.is_open()) {
        throw std::invalid_argument("Error! Cannot open file " + inputFileName + "!\n");
    }

    std::string tmpString;

    while (std::getline(inputFile, tmpString)) {
      std::stringstream strStream;
      strStream << tmpString;

      std::string vectorType;
      strStream >> vectorType;
      //std::cout << vectorType << std::endl;
      std::string fileName;
      strStream >> fileName;

      EL_TYPE el;
      std::list<EL_TYPE> elementsList;
      while (strStream >> el) {
        elementsList.push_back(el);
      }

      auto curFactory = factoryMap.find(vectorType);
      if (curFactory == factoryMap.end()) {
        throw std::invalid_argument("Error! Wrong type of vector in file input.txt!\n");
      }

      auto curVect = curFactory->second->Create(static_cast<unsigned int>(elementsList.size()), fileName);
      unsigned int i = 0;
      /* range-based loop */
      for (const auto el : elementsList) {
        (*curVect)[i] = el;
        i++;
      }

      vectorVector.emplace_back(curVect);
    }

    inputFile.close();

    /* range-based loop */
    for (const auto& vect : vectorVector) {
      vect->Output();
    }

    return 0;
  }

  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}

