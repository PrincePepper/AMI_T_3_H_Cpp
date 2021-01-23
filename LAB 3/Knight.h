#pragma once

class Knight : public Character {
 public:
  Knight() {
    SetSym('H');
    SetDamage(heroDamage);
    SetHp(heroHealth);
    SetPos(Point(0, 0));
    SetAmmo(heroAmmo);
  }

  void move(Map &map) override {}
 private:
  int heroDamage = 1;

  int heroAmmo = 7;
};
