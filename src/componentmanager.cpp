#include "componentmanager.h"

namespace gxy {

ComponentManager::ComponentManager(const std::shared_ptr<Game> game) : mixins::Gameable(game)
{
}

} // namespace gxy
