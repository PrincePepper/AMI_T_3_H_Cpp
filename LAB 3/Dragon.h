#pragma once

class Dragon : public Enemy {
 public:
  Dragon(Map &map) : Enemy(map) {
    SetSym('D');
    SetDamage(dragonDamage);
    SetHp(dragonHealth);
  }

  Dragon(int x, int y) : Enemy(x, y) {
    SetSym('D');
    SetDamage(dragonDamage);
    SetHp(dragonHealth);
  }
 private:
  int dragonDamage = 5;

  int dragonHealth = 10000;
};
