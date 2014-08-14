#pragma once

class Game;

class Galaxy
{
public:
  Galaxy(Game &);
  Galaxy(const Galaxy &) = delete;
  Galaxy &operator =(const Galaxy) = delete;

  int exec();

private:
  Game &game_;
};

