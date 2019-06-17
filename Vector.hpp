#ifndef __VECTOR_HPP_INCLUDED__
#define __VECTOR_HPP_INCLUDED__

#include <string>
#include <fstream>
#include <stdexcept>

namespace VECTOR_HORI_VERT {

  template <typename T> class Vector {
  private:
    std::string filename_;
    unsigned int size_;

  protected:
    T* vector_;

  public:
    unsigned int get_size() const;
    std::string get_filename() const;
    T& operator[](unsigned int i);

    virtual void Output() const = 0;

    Vector() = delete;
    explicit Vector(unsigned int size, const std::string& filename);

    Vector(const Vector<T>& other);
    Vector& operator=(const Vector<T>& other);

    Vector(Vector<T>&& tmp);               // rvalue reference in move constructor
    Vector& operator=(Vector<T>&& tmp);    // rvalue reference in move assignment operator

    virtual ~Vector();
  };

} // namespace

#endif // __VECTOR_HPP_INCLUDED__
