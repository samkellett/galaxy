#ifndef GALAXY_GAMEOBJECT_H
#define GALAXY_GAMEOBJECT_H

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include <boost/optional.hpp>

#include "componentmanager.h"
#include "mixins/gameable.h"

namespace gxy {

class Game;

class GameObject : public mixins::Gameable
{
public:
  GameObject(Game &game, const std::string &name, const boost::optional<GameObject &> &parent = boost::optional<GameObject &>());

  const std::string &name() const;

  ComponentManager &components();

  void setParent(GameObject &parent);
  const boost::optional<GameObject &> &parent() const;

  void addChild(GameObject &child);
  const std::vector<std::reference_wrapper<GameObject>> &children() const;

private:
  const std::string name_;

  boost::optional<GameObject &> parent_;
  std::vector<std::reference_wrapper<GameObject>> children_;

  ComponentManager components_;
};

} // namespace gxy

#endif // GALAXY_GAMEOBJECT_H
