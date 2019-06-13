#ifndef __VECTORHORI_HPP_INCLUDED__
#define __VECTORHORI_HPP_INCLUDED__

#include "Vector.hpp"

namespace VECTOR_HORI_VERT {

  template <typename T> class VectorHori final : public Vector<T> {
  public:
    using Vector<T>::operator=;
    //using Vector<T>::operator[];
    virtual void Output() const override final;

    template <typename T1>
    friend VectorHori<T1> operator+(Vector<T1>& first, Vector<T1>& second);

    VectorHori() = delete;
    explicit VectorHori(unsigned int size, std::string filename);

    VectorHori(const Vector<T>& other);
    VectorHori(const VectorHori<T>& other);
    VectorHori(Vector<T>&& tmp);
    ~VectorHori();
  };

} // namespace

#endif // __VECTORHORI_HPP_INCLUDED__
