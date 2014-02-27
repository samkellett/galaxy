#ifndef GALAXY_OBJECTS_CAMERA_H
#define GALAXY_OBJECTS_CAMERA_H

#include "../gameobject.h"

namespace gxy {
namespace objects {

class Camera : public GameObject
{
public:
  Camera(const char *const name);
};

} // namespace object
} // namespace gxy

#endif // GALAXY_OBJECTS_CAMERA_H
