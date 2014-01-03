#ifndef GALAXY_STATEMANAGER_H
#define GALAXY_STATEMANAGER_H

#include <cstdint>
#include <memory>
#include <vector>

#include "scene.h"

namespace galaxy {

class StateManager
{
public:
  StateManager();
  ~StateManager();

  template <typename State>
  std::shared_ptr<Scene> push();

  const std::shared_ptr<Scene> at(int32_t i);
  const int32_t size();

  const std::shared_ptr<Scene> pop_back();

  const std::shared_ptr<Scene> front();
  const std::shared_ptr<Scene> back();

private:
  std::vector<std::shared_ptr<Scene>> states_;
};

} // namespace galaxy

#include "statemanager.tpp"
#endif
