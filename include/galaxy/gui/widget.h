#ifndef GALAXY_WIDGET_H
#define GALAXY_WIDGET_H

#include <chrono>
#include <memory>

#include "../mixins/gameable.h"

namespace gxy {

class Game;

namespace gui {

class Widget : public mixins::Gameable
{
public:
  Widget() = default;
  Widget(std::shared_ptr<Game> game);

  virtual void render(const std::chrono::nanoseconds &dt) = 0;
};

} // namespace gui
} // namespace gxy

#endif // GALAXY_WIDGET_H
