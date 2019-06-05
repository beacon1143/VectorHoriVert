#include <iostream>
#include <memory>

#include "Vector.hpp"
#include "Vector.cpp"
#include "VectorHori.hpp"
#include "VectorHori.cpp"
#include "VectorVert.hpp"
#include "VectorVert.cpp"

using namespace VECTOR_HORI_VERT;

int main() {
  try {
    std::shared_ptr<Vector<int>> a = std::make_shared<VectorHori<int>>(2, "test.txt");
    std::shared_ptr<Vector<int>> b = std::make_shared<VectorHori<int>>(2, "test.txt");
    (*a)[0] = 1;
    VectorVert<int> c(2, "test.txt");
    VectorVert<int> d = *a + *b;
    c.Output();
    d.Output();

    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}

