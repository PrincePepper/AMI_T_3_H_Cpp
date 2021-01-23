#pragma once

#include "Point.h"
#include "Map.h"

class Character : public Point {

 public:
  Character() {};

  int attackRadius = 1;

  int GetHp() { return health; }

  int GetDamage() { return damage; }

  void SetHp(int hp) {
    this->health = hp;
  }

  void SetDamage(int damage) {
    this->damage = damage;
  }
  void SetAmmo(int ammo) { this->ammo = ammo; }

  int GetAmmo() { return ammo; }

  Point GetPos() { return position; }

  char GetSym() { return sym; }

  void SetPos(Point position) { this->position = position; }

  void SetSym(char sym) { this->sym = sym; }

  virtual void move(Map &map) = 0;

  [[nodiscard]] bool in_attack_radius(const Point other) const {
    return abs(abs(abs(this->position.x) - abs(other.x))
                   + abs(abs(this->position.y) - abs(other.y))) <= 1;
  }

 protected:
  Point get_spawn_point(Map &map) {
    position.x = 3 + (rand()) % (xy.x - 5);
    position.y = 3 + (rand()) % (xy.y - 5);
    while (!map.is_empty(position)) {
      position.x = 3 + (rand()) % (xy.x - 5);
      position.y = 3 + (rand()) % (xy.y - 5);
    }
    map.coords.push_back(position);
    return position;
  }

 private:

  int damage;

  int health;

  int ammo = 10000;

  Point position;

  char sym;
};

