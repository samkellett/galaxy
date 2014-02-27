
namespace gxy {

template <std::size_t Base, typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type is_base(T i)
{
  while (i > 0) {
    if ((i % 10) >= Base) {
      return false;
    }

    i /= 10;
  }

  return true;
}

} // namespace gxy
