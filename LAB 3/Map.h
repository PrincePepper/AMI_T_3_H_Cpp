#pragma once

#include <algorithm>
#include <vector>
#include "Point.h"

int heroHealth = 7;

Point xy = Point(25, 25);

class Map {
 public:
  std::vector<std::string> gameField;

  std::vector<Point> coords;

  Map() = default;

  void clear_game_field() {
    gameField = std::vector<std::string>(xy.y, std::string(xy.x, '.') + '\n');
  }

  bool is_empty(Point pos) {
    return std::find(coords.begin(), coords.end(), pos) == coords.end();
  }

  static bool in_game_field(Point pos) {
    return pos.x >= 0 && pos.x < xy.x && pos.y >= 0 && pos.y < xy.y;
  }
};
