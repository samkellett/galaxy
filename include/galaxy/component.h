#ifndef GALAXY_COMPONENT_H
#define GALAXY_COMPONENT_H

#include <chrono>
#include <memory>

#include "mixins/gameable.h"

namespace YAML { class Node; }

namespace gxy {

class Game;

class Component : public mixins::Gameable
{
public:
  virtual void init();

  virtual void update(const std::chrono::nanoseconds &dt) = 0;
  virtual void render(const std::chrono::nanoseconds &dt) = 0;

  void setTypeAndName(const std::string &type, const std::string &name);
  const std::string &type() const;
  const std::string &name() const;

private:
  std::string name_;
  std::string type_;
};

std::shared_ptr<Component> load_component(const std::shared_ptr<Game> game, const YAML::Node &data);

} // namespace gxy

#endif // GALAXY_COMPONENT_H
