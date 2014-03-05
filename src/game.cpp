#include "game.h"

#include <cassert>

#include <glog/logging.h>
#include <yaml-cpp/yaml.h>

#include "component.h"

namespace gxy {

Game::Game(const boost::filesystem::path &config) :
  config_(config)
{
}

void Game::init()
{
  scenes().setGame(shared_from_this());
  auto config = YAML::LoadFile(config_.string());

  title_ = config["title"].as<std::string>();
  assets_ = boost::filesystem::path(config["assets"].as<std::string>());
  if (assets_.is_relative()) {
    assets_ = config_.parent_path() / assets_;
  }

  width_ = config["width"].as<unsigned int>();
  height_ = config["height"].as<unsigned int>();

  LOG(INFO) << "Creating new game: " << title_;
  LOG(INFO) << "Assets directory: " << assets_.string();

  LOG(INFO) << "Processing scenes...";
  scenes() << config["scenes"];

  assert(!scenes().empty());
  LOG(INFO) << "First scene: " << scenes().front();
}

const std::string &Game::title() const
{
  return title_;
}

const boost::filesystem::path &Game::assets() const
{
  return assets_;
}

unsigned int Game::width() const
{
  return width_;
}

unsigned int Game::height() const
{
  return height_;
}

const Game::ComponentLoader &Game::component(const std::string &id) const
{
  assert(loaders_.count(id) == 1);
  return loaders_.at(id);
}

SceneManager &Game::scenes()
{
  return scenes_;
}

component_id_exists::component_id_exists(const std::string &id) :
  std::runtime_error(std::string("The component id: ") + id + " has already been registered for a different component.")
{
}

} // namespace gxy
