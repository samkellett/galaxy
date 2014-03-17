#ifndef GALAXY_GALAXY_H
#define GALAXY_GALAXY_H

namespace gxy {

class Game;

class Galaxy final
{
public:
  Galaxy(Game &game);
  Galaxy(const Galaxy &) = delete;
  Galaxy &operator =(Galaxy) = delete;

  int exec();

private:
  Game &game_;
};

} // namespace gxy

#endif // GALAXY_GALAXY_H
