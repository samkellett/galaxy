#pragma once

#include <map>
#include <string>

#include "gxy/macros.h"

namespace {

} // unnamed namespace

namespace gxy {
namespace test {

class FunctionCallMap
{
public:
  int &operator[] (const std::string &key);

  template <typename T>
  T default_value(const std::string &method);

private:
  std::map<std::string, int> call_map_;
};

template <typename T>
T FunctionCallMap::default_value(const std::string &method)
{
  GXY_UNUSED(method);

  return T();
}

extern FunctionCallMap function_call_map;

} // namespace test
} // namespace gxy
