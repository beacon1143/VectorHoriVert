#ifndef __FACTORY_HPP_INCLUDED__
#define __FACTORY_HPP_INCLUDED__

#include <memory>
#include "Vector.hpp"

namespace VECTOR_HORI_VERT {

  template <typename T> class Factory {
  public:
    virtual std::shared_ptr<Vector<T>> Create(const unsigned int size, std::string filename) const = 0;

    Factory() = default;
    virtual ~Factory() = default;
  };

} // namespace

#endif // __FACTORY_HPP_INCLUDED__
