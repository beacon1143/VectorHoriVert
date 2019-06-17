#ifndef __FACTORYVERT_HPP_INCLUDED__
#define __FACTORYVERT_HPP_INCLUDED__

#include <memory>
#include "Vector.hpp"
#include "VectorVert.hpp"

namespace VECTOR_HORI_VERT {

  template <typename T>
  class FactoryVert : public Factory<T> {
  public:
    virtual std::shared_ptr<Vector<T>> Create(const unsigned int size, const std::string& filename) const override final {
      return std::make_shared<VectorVert<T>>(size, filename);
    }

    FactoryVert() = default;
    ~FactoryVert() = default;
  };

} // namespace

#endif // __FACTORYVERT_HPP_INCLUDED__
