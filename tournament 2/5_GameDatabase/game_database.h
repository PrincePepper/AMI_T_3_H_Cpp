//
// Created by User on 01.11.2020.
//
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <functional>
#include <utility>
#include <string>

#ifndef PMI_T_3_H_CPP_TOURNAMENT_2_5_GAMEDATABASE_GAME_DATABASE_H_
#define PMI_T_3_H_CPP_TOURNAMENT_2_5_GAMEDATABASE_GAME_DATABASE_H_

bool operator>(const GameObject &a, const GameObject &b) {
  return a.id > b.id;
}

template<class Tp, template<class> class Compare>
class DereferenceCompare {
  Compare<Tp> comp;

 public:
  bool operator()(const Tp *const a, const Tp *const b) const {
    return comp(*a, *b);
  }
};

class GameDatabase {
 public:
  GameDatabase() = default;

  /// вставляет в базу объект с именем [name] и позицией [x, y]
  /// если объект с таким id в базе уже есть, заменяет его новым
  void Insert(ObjectId id, const string &name, size_t x, size_t y) {
    GameObject new_field = {id, name, x, y};
    if (idmap.find(id) != idmap.end()) Remove(id);

    idmap.insert({id, new_field});
    posmap[{x, y}].insert(&idmap.at(id));
    namemap[name].insert(&idmap.at(id));
  }

  /// удаляет элемент по id
  /// если такого элемента нет, ничего не делает
  void Remove(ObjectId id) {
    if (idmap.find(id) != idmap.end()) {
      GameObject *temp = &idmap.find(id)->second;
      posmap.find({temp->x, temp->y})->second.erase(temp);
      namemap.find(temp->name)->second.erase(temp);
      idmap.erase(idmap.find(id));
    }
  }

  /// возвращает вектор объектов c именем [name]
  /// сортировка по убыванию id
  vector<GameObject> DataByName(string name) const {
    vector<GameObject> temp;

    if (namemap.find(name) == namemap.end()) return temp;

    auto b = namemap.find(name)->second.begin();
    while (b != namemap.find(name)->second.end()) {
      temp.push_back(**b);
      b++;
    }
    return temp;
  }

  /// возвращает вектор объектов, находящихся в позиции [x, y]
  /// сортировка по убыванию id
  vector<GameObject> DataByPosition(size_t x, size_t y) const {
    vector<GameObject> temp;

    if (posmap.find({x, y}) == posmap.end()) return temp;

    auto b = posmap.find({x, y})->second.begin();
    while (b != posmap.find({x, y})->second.end()) {
      temp.push_back(**b);
      b++;
    }
    return temp;
  }

  /// возвращает вектор всех объектов из базы
  /// сортировка по убыванию id
  vector<GameObject> Data() const {
    vector<GameObject> temp;

    auto it = idmap.begin();
    while (it != idmap.end()) {
      temp.push_back(it->second);
      it++;
    }
    return temp;
  }

 private:
  /// быстрый доступ по id
  std::map<ObjectId, GameObject, std::greater<>> idmap;

  /// быстрый доступ по позиции
  std::map<std::pair<size_t, size_t>,
           std::set<GameObject *, DereferenceCompare<GameObject, std::greater>>>
      posmap;

  /// быстрый доступ по имени
  std::unordered_map<string,
                     std::set<GameObject *,
                              DereferenceCompare<GameObject, std::greater>>>
      namemap;
};

#endif  // PMI_T_3_H_CPP_TOURNAMENT_2_5_GAMEDATABASE_GAME_DATABASE_H_
