#pragma once

#include "Map.h"
#include "Character.h"
#include "Knight.h"
#include "Gunsight.h"
#include "Princess.h"
#include "Medkit.h"
#include "Zombie.h"
#include "Dragon.h"
#include "Shooter.h"
#include "Wall.h"
#include <memory>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <memory>
#include <iostream>
#include <curses.h>
#include <unistd.h>

class GameLoop {
 private:
  bool shoot_mode = false;

  Map map;

  std::vector<std::shared_ptr<Character>> entities;

  std::unordered_map<Point, std::shared_ptr<Character>, CoordsHash>
      entitiesByPos;

  void refresh_game_field() {
    map.clear_game_field();
    entitiesByPos.clear();

    for (const auto &entity : entities) {
      if (entity == nullptr)
        continue;
      if (entity->GetSym() == '@' && !shoot_mode)
        continue;
      entity->move(map);
      if (!map.in_game_field(entity->GetPos()) || (entity->GetSym() == '*'
          && entitiesByPos.find(entity->GetPos()) != entitiesByPos.end())) {
        entitiesByPos[Point(entity->GetPos().x, entity->GetPos().y)] = entity;
        delete_entity(entity);
        continue;
      }
      map.gameField[entity->GetPos().y][entity->GetPos().x] = entity->GetSym();
      entitiesByPos[Point(entity->GetPos().x, entity->GetPos().y)] = entity;
      if (entity->GetSym() != 'H' && entity->GetSym() != '@'
          && entity->GetAmmo() > 0
          && entity->in_attack_radius(entities[0]->GetPos())) {

        entities[0]->SetHp(entities[0]->GetHp() - entity->GetDamage());
        entity->SetAmmo(entity->GetAmmo() - 1);

        if (entities[0]->GetHp() > heroHealth)

          entities[0]->SetHp(heroHealth);
      }

      if (entity->GetHp() == 0)
        delete_entity(entity);
    }
    if (shoot_mode) {
      map.gameField[entities[2]->GetPos().y][entities[2]->GetPos().x] =
          entities[2]->GetSym();
    }
  }

  void show_game_field() {
    if (entities[0]->GetHp() <= 0)
      show_end_screen(false);
    if (entities[0]->in_attack_radius(entities[1]->GetPos()))
      show_end_screen(true);

    for (int i = 0; i < map.gameField.size(); i++)
      mvprintw(i, 0, map.gameField[i].c_str());

    std::string status =
        "HP: " + std::__cxx11::to_string(entities[0]->GetHp()) + " Ammo: "
            + std::__cxx11::to_string(entities[0]->GetAmmo());
    mvprintw(map.gameField.size(), 0, status.c_str());
    refresh();
  }

  void show_end_screen(bool victory) {
    clear();
    mvprintw(0, 0, victory ? "You win" : "You lose");
    nodelay(stdscr, FALSE);
    getch();
    endwin();
    exit(0);
  }

  void move_hero(int key) {
    Point dir;
    switch (key) {
      case KEY_DOWN:dir = Point(0, 1);
        break;
      case KEY_UP:dir = Point(0, -1);
        break;
      case KEY_LEFT:dir = Point(-1, 0);
        break;
      case KEY_RIGHT:dir = Point(1, 0);
        break;
      case 's':
      case 'S':dir = Point(0, 0);
        change_mode();
        break;
      default:dir = Point(0, 0);
        break;
    }

    if (entities[0]->GetAmmo() <= 0)
      shoot_mode = false;

    check_collision(entities[shoot_mode ? 2 : 0], dir);
    refresh();
  }

  void change_mode() {
    if (!shoot_mode)
      entities[2]->SetPos(entities[0]->GetPos());
    else
      entities[2]->SetPos(Point(-1, -1));
    shoot_mode = !shoot_mode;
  }

  void check_collision(const std::shared_ptr<Character> entity, Point dir) {
    Point
        newPos = Point(entity->GetPos().x + dir.x, entity->GetPos().y + dir.y);

    if (Map::in_game_field(newPos)) {
      if (map.gameField[newPos.y][newPos.x] == '.'
          || map.gameField[newPos.y][newPos.x] == 'H'
          || map.gameField[newPos.y][newPos.x] == '@') {
        entity->SetPos(newPos);
      } else {
        std::shared_ptr<Character> secondEntity = entitiesByPos.at(newPos);
        secondEntity->SetHp((secondEntity->GetHp() - entity->GetDamage()));
        if (shoot_mode && secondEntity->GetDamage() > 0)
          entities[0]->SetAmmo(entities[0]->GetAmmo() - 1);
        if (shoot_mode && secondEntity->GetDamage() <= 0)
          entity->SetPos(newPos);
        if (secondEntity->GetHp() <= 0) {
          delete_entity(secondEntity);
          entity->SetPos(newPos);
        }
      }
    }
  }

  void delete_entity(const std::shared_ptr<Character> &entity) {
    auto itObjByPos = entitiesByPos.find(entity->GetPos());
    auto itPos = find(map.coords.begin(), map.coords.end(), entity->GetPos());
    auto itObj = find(entities.begin(), entities.end(), entity);
    entitiesByPos.erase(itObjByPos);
    map.coords.erase(itPos);
    entities.erase(itObj);
  }

 public:
  GameLoop() {
    map = Map();
    map.clear_game_field();
    entities.push_back(std::make_shared<Knight>());
    entities.push_back(std::make_shared<Princess>());
    for (int i = 0; i < 2; i++)
      entities.push_back(std::make_shared<Gunsight>());
    for (int i = 0; i < 2; i++)
      entities.push_back(std::make_shared<Dragon>(map));
    for (int i = 0; i < 5; i++)
      entities.push_back(std::make_shared<Medkit>(map));
    for (int i = 0; i < 200; i++)
      entities.push_back(std::make_shared<Wall>(map));
    for (int i = 0; i < 15; i++)
      entities.push_back(std::make_shared<Zombie>(map));
    for (int i = 0; i < 15; i++)
      entities.push_back(std::make_shared<Shooter>(map));

    for (const auto &entity : entities)
      entitiesByPos[Point(entity->GetPos().x, entity->GetPos().y)] = entity;
  }

  [[noreturn]] void start() {
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    auto last_time_enemies_moved = std::chrono::steady_clock::now();

    while (true) {
      int key = getch();
      if (key != -1) {
        move_hero(key);
        refresh_game_field();
        show_game_field();
        last_time_enemies_moved = std::chrono::steady_clock::now();
      } else {
        if (std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - last_time_enemies_moved).count()
            > 1000) {
          refresh_game_field();
          show_game_field();
          last_time_enemies_moved = std::chrono::steady_clock::now();
        }
      }
    }
  }
};