#include "game.h"

#include <cassert>

#include <glog/logging.h>
#include <yaml-cpp/yaml.h>

#include "component.h"

namespace gxy {

Game::Game(const std::string &config_file) :
  scenes_(shared_from_this())
{
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

std::shared_ptr<Component> Game::loadComponent(const std::string &id, const YAML::Node &data)
{
  assert(loaders_.find(id) != loaders_.end());

  std::shared_ptr<Component> component = loaders_.at(id)(data);
  component->setGame(shared_from_this());

  return component;
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
