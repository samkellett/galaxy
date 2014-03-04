#ifndef GXY_MIXINS_REGISTERABLE_H
#define GXY_MIXINS_REGISTERABLE_H

#include <memory>

namespace YAML { class Node; }

namespace gxy {

class Component;

namespace mixins {

template <typename T>
class Registerable
{
public:
  static std::shared_ptr<Component> registerComponent(const YAML::Node &node);
};

} // namespace mixins
} // namespace gxy

#include "registerable.hpp"
#endif // GXY_MIXINS_REGISTERABLE_H
