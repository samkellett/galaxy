#include "gxy/test/functioncallmap.h"

namespace gxy {
namespace test {

int &function_call_map::operator[] (const std::string &key)
{
  return call_map_[key];
}

} // namespace test
} // namespace gxy

