#ifndef GALAXY_GALAXY_H
#define GALAXY_GALAXY_H

namespace gxy {

class Game;

class Galaxy
{
public:
  Galaxy(Game &game);

  int exec();
  
private:
  Game &game_;
};

} // namespace gxy

#endif // GALAXY_GALAXY_H
