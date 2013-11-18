#ifndef GALAXY_GAME_H
#define GALAXY_GAME_H

namespace galaxy {

class Game
{
public:
  Game(const char *title);

  const char *title() const;

protected:
  const char *title_;
};

} // namespace galaxy

#endif // GALAXY_GAME_H