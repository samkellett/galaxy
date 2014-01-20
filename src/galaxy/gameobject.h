#ifndef GALAXY_GAMEOBJECT_H
#define GALAXY_GAMEOBJECT_H

#include <chrono>
#include <memory>
#include <vector>

#include "componentmanager.h"

namespace glxy {

class GameObject : public std::enable_shared_from_this<GameObject>
{
public:
  GameObject(const char *const name, const std::shared_ptr<GameObject> &parent = nullptr);
  ~GameObject();

  const char *const name() const;

  ComponentManager &components();

  void setParent(const std::shared_ptr<GameObject> &parent);
  const std::shared_ptr<GameObject> parent() const;

  void addChild(const std::shared_ptr<GameObject> &child);
  const std::vector<std::shared_ptr<GameObject>> children() const;

private:
  const char *const name_;

  std::shared_ptr<GameObject> parent_;
  std::vector<std::shared_ptr<GameObject>> children_;

  ComponentManager components_;
};

} // namespace glxy

#endif // GALAXY_GAMEOBJECT_H
