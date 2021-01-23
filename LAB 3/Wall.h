#pragma once

class Wall : public Character {
 public:
  Wall(Map &map) {
    SetSym('#');
    SetDamage(0);
    SetHp(100000);
    SetPos(get_spawn_point(map));
  }

  Wall(int x, int y) {
    SetSym('#');
    SetDamage(0);
    SetHp(100000);
    SetPos(Point(x, y));
  }

  void move(Map &map) override {}
};
