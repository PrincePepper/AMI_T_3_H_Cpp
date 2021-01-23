#pragma once

class Medkit : public Character {
 public:
  Medkit(Map &map) {
    SetSym('+');
    SetDamage(-medKitPower);
    SetHp(1);
    SetPos(get_spawn_point(map));
  }

  Medkit(int x, int y) {
    SetSym('+');
    SetDamage(-medKitPower);
    SetHp(1);
    SetPos(Point(x, y));
  }

  void move(Map &map) override {}

 private:
  int medKitPower = 1;
};
