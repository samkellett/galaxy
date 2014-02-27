
namespace gxy {

constexpr ShaderType begin(const ShaderType &)
{
  return ShaderType::Vertex;
}

constexpr ShaderType end(const ShaderType &)
{
  return static_cast<ShaderType>(ShaderType::Fragment << 1);
}

} // namespace gxy
