#include "VectorVert.hpp"

namespace VECTOR_HORI_VERT {

  template <typename T>
  void VectorVert<T>::Output() const {
    std::ofstream fil;
    fil.open(this->get_filename().c_str(), std::ios_base::app);
    if (!fil.is_open()) {
      throw std::invalid_argument("Error! Cannot open file " + this->get_filename() + "!\n");
    }

    for (unsigned int i = 0; i < this->get_size(); i++) {
      fil << this->vector_[i] << '\n';
    }

    fil.close();
  }

  /*template <typename T>
  VectorHori<T>::VectorHori() {
  }*/

  template <typename T>
  VectorVert<T>::VectorVert(const unsigned int size, std::string filename)
    : Vector<T>(size, filename)
  {
  }

  template <typename T>
  VectorVert<T>::VectorVert(const Vector<T>& other)
    : Vector<T>(other)
  {
  }

  template <typename T>
  VectorVert<T>::VectorVert(VectorVert<T>&& tmp)
    : Vector<T>(tmp)
  {
  }

  template <typename T>
  VectorVert<T>::~VectorVert() {
  }

} // namespace
