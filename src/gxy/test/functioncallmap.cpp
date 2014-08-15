#include "gxy/test/functioncallmap.h"

namespace gxy {
namespace test {

int &FunctionCallMap::operator[] (const std::string &key)
{
  return call_map_[key];
}

FunctionCallMap function_call_map;

} // namespace test
} // namespace gxy
