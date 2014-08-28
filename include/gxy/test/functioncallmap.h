#pragma once

#include <map>
#include <string>

#include "gxy/macros.h"

namespace {

} // unnamed namespace

namespace gxy {
namespace test {

class function_call_map
{
public:
  int &operator[] (const std::string &key);

  bool empty() const;
  void clear();

  template <typename T>
  T default_value(const std::string &method);

private:
  std::map<std::string, int> call_map_;
};

template <typename T>
T function_call_map::default_value(const std::string &method)
{
  GXY_UNUSED(method);

  return T();
}

} // namespace test
} // namespace gxy
