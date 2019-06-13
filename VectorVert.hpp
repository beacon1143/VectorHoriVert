#ifndef __VECTORVERT_HPP_INCLUDED__
#define __VECTORVERT_HPP_INCLUDED__

#include "Vector.hpp"

namespace VECTOR_HORI_VERT {

  template <typename T> class VectorVert final : public Vector<T> {
  public:
    using Vector<T>::operator=;
    //using Vector<T>::operator[];
    virtual void Output() const override final;

    //template <typename T>

    VectorVert() = delete;
    explicit VectorVert(unsigned int size, std::string filename);

    VectorVert(const Vector<T>& other);
    VectorVert(VectorVert<T>&& tmp);
    ~VectorVert();
  };

} // namespace

#endif // __VECTORVERT_HPP_INCLUDED__
