#pragma once

class Shooter : public Enemy {
 public:
  Shooter(Map &map) : Enemy(map) {
    SetSym('S');
    SetDamage(1);
    SetHp(1);
    SetAmmo(1);
  }

  Shooter(int x, int y) : Enemy(x, y) {
    SetSym('S');
    SetDamage(1);
    SetHp(1);
    SetAmmo(1);
  }
};
