#include <cmath>

#include "traits.h"

namespace gxy {

template <std::size_t From, std::size_t To, typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type base_cast(T t)
{
  assert(gxy::is_base<From>(t));

  T output = 0;
  for (T i = 0; t > 0; ++i) {
    if (t % To == 1) {
      output += std::pow(From, i);
    }

    t /= To;
  }

  return output;
}

} // namespace gxy
