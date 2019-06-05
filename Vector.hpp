#ifndef __VECTOR_HPP_INCLUDED__
#define __VECTOR_HPP_INCLUDED__

#include <string>
#include <fstream>
#include <stdexcept>

namespace VECTOR_HORI_VERT {

  template <typename T> class Vector {
  protected:
    std::string filename_;
    unsigned int size_;
    T* vector_;
  public:
    unsigned int get_size() const;
    std::string get_filename() const;
    T& operator[](unsigned int i);

    virtual void Output() const = 0;

    Vector() = delete;
    explicit Vector(int size, std::string filename);
    Vector(const Vector<T>& other);
    Vector& operator=(const Vector<T>& other);
    Vector(Vector<T>&& tmp);
    Vector& operator=(Vector<T>&& tmp);

    virtual ~Vector();
  };

} // namespace

#endif // VECTOR_H
