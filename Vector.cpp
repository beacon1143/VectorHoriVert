#include "Vector.hpp"

namespace VECTOR_HORI_VERT {

  template <typename T>
  unsigned int Vector<T>::get_size() const {
    return size_;
  }

  template <typename T>
  std::string Vector<T>::get_filename() const {
    return filename_;
  }

  /*template <typename T>
  Vector<T>::Vector() {
    size_ = 0;
    vector_ = nullptr;
  }*/

  template <typename T>
  Vector<T>::Vector(const unsigned int size, std::string filename) {
    filename_ = filename;

    // output file cleanup
    std::ofstream fil;
    fil.open(filename_.c_str(), std::ios_base::out | std::ios::trunc);
    if (!fil.is_open()) {
      throw std::invalid_argument("Error! Cannot open file " + filename_ + "!\n");
    }
    fil.close();

    size_ = size;
    vector_ = new T[size_];
    for (unsigned int i = 0; i < size_; i++) {
      vector_[i] = static_cast<T>(0);
    }
  }

  /* copy constructor and assignment operator */

  template <typename T>
  Vector<T>::Vector(const Vector<T>& other) {
    filename_ = other.filename_;
    size_ = other.size_;
    vector_ = new T[size_];
    for (unsigned int i = 0; i < size_; i++) {
      vector_[i] = other.vector_[i];
    }
  }

  template <typename T>
  Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    filename_ = other.filename_;
    size_ = other.size_;
    if (vector_) {
      delete vector_;
    }
    vector_ = new T[size_];
    for (unsigned int i = 0; i < size_; i++) {
      vector_[i] = other.vector_[i];
    }
    return *this;
  }

  /* move constructor and copy assignment operator */

  template <typename T>
  Vector<T>::Vector(Vector<T>&& tmp) {
    filename_ = tmp.filename_;
    size_ = tmp.size_;
    vector_ = tmp.vector_;
    tmp.vector = nullptr;
  }

  template <typename T>
  Vector<T>& Vector<T>::operator=(Vector<T>&& tmp) {
    filename_ = tmp.filename_;
    size_ = tmp.size_;
    if (vector_) {
      delete vector_;
    }
    vector_ = tmp.vector_;
    tmp.vector_ = nullptr;
    return *this;
  }

  template <typename T>
  T& Vector<T>::operator[](unsigned int i) {
    if (i >= size_) {
      throw std::out_of_range("Error: Index is out of range!\n");
    }
    return vector_[i];
  }

  template <typename T>
  Vector<T>::~Vector() {
    size_ = 0;
    delete[] vector_;
  }

} // namespace
