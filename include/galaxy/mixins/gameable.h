#ifndef GXY_MIXINS_GAMEABLE
#define GXY_MIXINS_GAMEABLE

#include <memory>

namespace gxy {

class Game;

namespace mixins {

class Gameable
{
public:
  std::shared_ptr<Game> game();
  std::shared_ptr<Game> game() const;
  void setGame(const std::shared_ptr<Game> game);

protected:
  Gameable() = default;
  Gameable(std::shared_ptr<Game> game);

private:
  std::shared_ptr<Game> game_;
};

} // namespace mixins
} // namespace gxy

#endif // GXY_MIXINS_GAMEABLE
