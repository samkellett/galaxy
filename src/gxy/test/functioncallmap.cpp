#include "gxy/test/functioncallmap.h"

namespace gxy {
namespace test {

int &function_call_map::operator[] (const std::string &key)
{
  return call_map_[key];
}

bool function_call_map::empty() const
{
  return call_map_.empty();
}

void function_call_map::clear()
{
  call_map_.clear();
}

function_call_map gfmap;

} // namespace test
} // namespace gxy

