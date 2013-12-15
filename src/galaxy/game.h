#ifndef GALAXY_GAME_H
#define GALAXY_GAME_H

namespace galaxy {

class Game
{
public:
  Game();
  Game(const char * const title);
  Game(const char * const title, const uint32_t width, const uint32_t height);

  const char * const title() const;
  const uint32_t width() const;
  const uint32_t height() const;

protected:
  const char * const title_;

  const uint32_t width_;
  const uint32_t height_;
};

} // namespace galaxy

#endif // GALAXY_GAME_H