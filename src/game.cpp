#include "game.h"

#include <cassert>

#include <glog/logging.h>
#include <yaml-cpp/yaml.h>

namespace gxy {

Game *Game::game = nullptr;

Game::Game(const std::string &config_file)
{
  assert(game == nullptr);
  game = this;

  YAML::Node config = YAML::LoadFile(config_file);

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

SceneManager &Game::scenes()
{
  return scenes_;
}

} // namespace gxy
