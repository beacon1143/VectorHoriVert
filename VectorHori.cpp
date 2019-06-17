#include "VectorHori.hpp"

namespace VECTOR_HORI_VERT {

  template <typename T>
  void VectorHori<T>::Output() const {
    std::ofstream fil;
    fil.open(this->get_filename().c_str(), std::ios_base::app);
    if (!fil.is_open()) {
      throw std::invalid_argument("Error! Cannot open file " + this->get_filename() + "!\n");
    }

    for (unsigned int i = 0; i < this->get_size(); i++) {
      fil << this->vector_[i] << ' ';
    }
    fil << std::endl;

    fil.close();
  }

  template <typename T1>
  VectorHori<T1> operator+(Vector<T1>& first, Vector<T1>& second) {
    if ( first.get_size() != second.get_size() ) {
      throw std::invalid_argument("Error! Vectors have different lengths!\n");
    }
    VectorHori<T1> retVector( first.get_size(), first.get_filename() );
    for (unsigned int i = 0; i < retVector.size_; i++) {
      retVector.vector_[i] = first[i] + second[i];
    }
    return retVector;
  }

  /*template <typename T>
  VectorHori<T>::VectorHori() {
  }*/

  template <typename T>
  VectorHori<T>::VectorHori(const unsigned int size, std::string filename)
    : Vector<T>(size, filename)
  {
  }

  template <typename T>
  VectorHori<T>::VectorHori(const Vector<T>& other)
    : Vector<T>(other)
  {
  }

  template <typename T>
  VectorHori<T>::VectorHori(const VectorHori<T>& other)
    : Vector<T>(other)
  {
  }

  template <typename T>
  VectorHori<T>::VectorHori(Vector<T>&& tmp)
    : Vector<T>(tmp)
  {
  }

  template <typename T>
  VectorHori<T>::~VectorHori() {
  }

} // namespace
