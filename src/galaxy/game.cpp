#include "game.h"

#include <cassert>
#include <chrono>

#include <glog/logging.h>

namespace galaxy {

Game *Game::game = nullptr;

Game::Game() : Game("Dark Matter", ".", 640, 480)
{
}

Game::Game(const char *const title, const char *const assets) : Game(title, assets, 640, 480)
{
}

Game::Game(const char *const title, const char *assets, uint32_t width, uint32_t height) :
  title_(title), assets_(assets), width_(width), height_(height)
{
  assert(game == nullptr);
  game = this;

  LOG(INFO) << "Creating new game: " << title_;

  auto ret = FT_Init_FreeType(&freetype_);
  assert(ret == 0);
}

Game *Game::instance()
{
  assert(game != nullptr);
  return game;
}

const char *const Game::title() const
{
  return title_;
}

const char *const Game::assets() const
{
  return assets_;
}

const uint32_t Game::width() const
{
  return width_;
}

const uint32_t Game::height() const
{
  return height_;
}

const std::shared_ptr<Scene> Game::currentScene()
{
  return scenes_.current();
}

SceneManager &Game::scenes()
{
  return scenes_;
}

std::map<const char *const, std::shared_ptr<FT_Face>> &Game::fonts()
{
  return fonts_;
}

void Game::addFont(const std::string &file) {
  size_t path = file.find_last_of("/\\");
  size_t ext = file.find_last_of(".");
  std::string font = file.substr(path + 1, ext - path - 1);

  auto face = std::make_shared<FT_Face>();
  std::string fullpath = std::string(assets_ + file);

  auto ret = FT_New_Face(freetype_, fullpath.c_str(), 0, face.get());
  assert(ret == 0);

  fonts_.insert({font.c_str(), face});
}

} // namespace galaxy
