
namespace gxy {

template <typename T>
constexpr typename std::enable_if<std::is_integral<T>::value, ShaderType>::type operator <<(const ShaderType &type, const T i)
{
  return static_cast<ShaderType>(static_cast<int>(type) << i);
}

template <typename T>
constexpr typename std::enable_if<std::is_integral<T>::value, ShaderType>::type operator >>(const ShaderType &type, const T i)
{
  return static_cast<ShaderType>(static_cast<int>(type) >> i);
}

} // namespace gxy

