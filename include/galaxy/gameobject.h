#ifndef GALAXY_GAMEOBJECT_H
#define GALAXY_GAMEOBJECT_H

#include <chrono>
#include <memory>
#include <string>
#include <vector>

#include "componentmanager.h"
#include "mixins/gameable.h"

namespace gxy {

class Game;

class GameObject : public std::enable_shared_from_this<GameObject>, public mixins::Gameable
{
public:
  GameObject(const std::shared_ptr<Game> game, const std::string &name, std::shared_ptr<GameObject> parent = nullptr);
  virtual ~GameObject() = default;

  const std::string &name() const;

  ComponentManager &components();

  void setParent(const std::shared_ptr<GameObject> &parent);
  const std::shared_ptr<GameObject> parent() const;

  void addChild(const std::shared_ptr<GameObject> &child);
  const std::vector<std::shared_ptr<GameObject>> children() const;

private:
  const std::string name_;

  std::shared_ptr<GameObject> parent_;
  std::vector<std::shared_ptr<GameObject>> children_;

  ComponentManager components_;
};

} // namespace gxy

#endif // GALAXY_GAMEOBJECT_H
