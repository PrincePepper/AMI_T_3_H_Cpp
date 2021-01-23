#pragma once

class Gunsight : public Character {
 public:
  Gunsight() {
    SetSym('@');
    SetDamage(heroDamage);
    SetHp(heroHealth);
    SetPos(Point(-1, -1));
  }

  void move(Map &map) override {}

 private:
  int heroDamage = 1;

  int heroHealth = 10000;
};
