#ifndef __FACTORYHORI_HPP_INCLUDED__
#define __FACTORYHORI_HPP_INCLUDED__

#include "Factory.hpp"
#include "Vector.hpp"
#include "VectorHori.hpp"

namespace VECTOR_HORI_VERT {

  template <typename T>
  class FactoryHori : public Factory<T> {
  public:
    virtual std::shared_ptr<Vector<T>> Create(const unsigned int size, std::string filename) const override final {
      return std::make_shared<VectorHori<T>>(size, filename);
    }

    FactoryHori() = default;
    ~FactoryHori() = default;
  };

} // namespace

#endif // __FACTORYHORI_HPP_INCLUDED__
