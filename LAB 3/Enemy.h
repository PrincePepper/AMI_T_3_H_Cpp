#pragma once

#include "Character.h"

class Enemy : public Character {
 public:
  explicit Enemy(Map &map) {
    SetPos(get_spawn_point(map));
  }
  Enemy(int x, int y) {
    SetPos(Point(x, y));
  }
  void move(Map &map) override {
    for (auto &dir : dirs)
      std::swap(dir, dirs[rand() % dirs.size()]);
    for (auto dir : dirs) {
      Point newPos = Point(GetPos().x + dir.x, GetPos().y + dir.y);
      if (map.is_empty(newPos) && map.in_game_field(newPos)) {
        replace_enemy(map, newPos);
        break;
      }
    }
  }

  void replace_enemy(Map &map, Point to) {
    map.coords.erase(find(map.coords.begin(), map.coords.end(), GetPos()));
    SetPos(to);
    map.coords.push_back(GetPos());
  }
 private:
  std::vector<Point> dirs = {Point(0, 1),
                             Point(1, 0),
                             Point(-1, 0),
                             Point(0, -1),
                             Point(0, 0)};
};
