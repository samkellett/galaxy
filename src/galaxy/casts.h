#ifndef GXY_CASTS_H
#define GXY_CASTS_H

#include <type_traits>

namespace gxy {

template <std::size_t from, std::size_t to, typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type base_cast(T t);

} // namespace gxy

#include "casts.tpp"
#endif // GXY_CASTS_H
