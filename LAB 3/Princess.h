#pragma once

class Princess : public Character {
 public:
  Princess() {
    SetSym('P');
    SetDamage(0);
    SetHp(100000);
    SetPos(Point(xy.x - 1, xy.y - 1));
  }

  void move(Map &map) override {}
};
