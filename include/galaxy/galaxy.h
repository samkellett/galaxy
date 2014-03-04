#ifndef GALAXY_GALAXY_H
#define GALAXY_GALAXY_H

#include <memory>

namespace gxy {

class Game;

class Galaxy final
{
public:
  Galaxy(const std::shared_ptr<Game> game);
  Galaxy(const Galaxy &) = delete;
  Galaxy &operator =(Galaxy) = delete;

  int exec();

private:
  const std::shared_ptr<Game> game_;
};

} // namespace gxy

#endif // GALAXY_GALAXY_H
