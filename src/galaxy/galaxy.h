#ifndef GALAXY_GALAXY_H
#define GALAXY_GALAXY_H

namespace galaxy {

class Game;

class Galaxy
{
public:
  Galaxy(Game &game);
  ~Galaxy();
  
  int exec();
  
private:
  Game &game_;
};

} // namespace galaxy

#endif // GALAXY_GALAXY_H
