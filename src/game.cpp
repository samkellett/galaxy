#include "game.h"

#include <cassert>

#include <glog/logging.h>
#include <yaml-cpp/yaml.h>

#include "component.h"

namespace gxy {

Game *Game::game = nullptr;

Game::Game(const std::string &config_file)
{
  assert(game == nullptr);
  game = this;

  auto config = YAML::LoadFile(config_file);

  title_ = config["title"].as<std::string>();
  assets_ = boost::filesystem::path(config["assets"].as<std::string>());
  if (assets_.is_relative()) {
    boost::filesystem::path path(config_file);
    assets_ = path.parent_path() / assets_;
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

Game *Game::instance()
{
  assert(game != nullptr);
  return game;
}

const std::string &Game::title() const
{
  return title_;
}

const boost::filesystem::path &Game::assets() const
{
  return assets_;
}

const unsigned int Game::width() const
{
  return width_;
}

const unsigned int Game::height() const
{
  return height_;
}

void Game::registerComponent(const std::string &id, const ComponentLoader &loader)
{
  if (loaders_.find(id) == loaders_.end()) {
    throw component_id_exists(id);
  }

  loaders_.insert({id, loader});
}

std::shared_ptr<Component> Game::loadComponent(const std::string &id, const YAML::Node &data)
{
  assert(loaders_.find(id) != loaders_.end());
 
  return loaders_.at(id)(data);
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
