#ifndef GALAXY_TEXT2D_H
#define GALAXY_TEXT2D_H

#include "../gameobject.h"

namespace galaxy {
namespace object {

class Text2D : public GameObject
{
public:
  struct Data
  {
    Data(const double x, const double y);

    double x;
    double y;
  };

  Text2D(const Data &data);

private:
  double x_;
  double y_;
};

} // namespace object
} // namespace galaxy

#endif // GALAXY_TEXT2D_H