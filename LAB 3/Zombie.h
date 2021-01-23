#pragma once

#include "Enemy.h"

class Zombie : public Enemy {
 public:
  Zombie(Map &map) : Enemy(map) {
    SetSym('Z');
    SetDamage(1);
    SetHp(1);
  }

  Zombie(int x, int y) : Enemy(x, y) {
    SetSym('Z');
    SetDamage(1);
    SetHp(1);
  }
};
