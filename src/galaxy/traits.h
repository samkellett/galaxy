#ifndef GXY_TRAITS_H
#define GXY_TRAITS_H

#include <type_traits>

namespace gxy {

template <std::size_t Base, typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type is_base(T i);

} // namespace gxy

#include "traits.hpp"
#endif // GXY_TRAITS_H
