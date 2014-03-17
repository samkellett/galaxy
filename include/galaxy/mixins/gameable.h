#ifndef GXY_MIXINS_GAMEABLE
#define GXY_MIXINS_GAMEABLE

#include <boost/optional.hpp>

namespace gxy {

class Game;

namespace mixins {

class Gameable
{
public:
  Game &game() const;
  void setGame(Game &game);

protected:
  Gameable() = default;
  Gameable(Game &game);

private:
  boost::optional<Game &> game_;
};

} // namespace mixins
} // namespace gxy

#endif // GXY_MIXINS_GAMEABLE
