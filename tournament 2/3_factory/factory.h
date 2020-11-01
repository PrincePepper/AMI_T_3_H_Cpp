//
// Created by User on 01.11.2020.
//
#include <map>
#include <string>
#include <utility>
#include <vector>

class Object {
 public:
  virtual std::string ToString() const = 0;

  virtual ~Object() {}
};

class Apple : public Object {
 public:
  explicit Apple(const std::string &class_id) {
    class_id_ = class_id;
  }

  std::string ToString() const override {
    return class_id_;
  }
 private:
  std::string class_id_;
};

Object *_new_apple_() {
  return new Apple("apple!");
}

class List : public Object {
 public:
  explicit List(const std::string &class_id) {
    class_id_ = class_id;
  }

  std::string ToString() const override {
    return class_id_;
  }
 private:
  std::string class_id_;
};

Object *_new_list_() {
  return new List("list");
}

class Yet_Another_Identifier : public Object {
 public:
  explicit Yet_Another_Identifier(const std::string &class_id) {
    class_id_ = class_id;
  }

  std::string ToString() const override {
    return class_id_;
  }

 private:
  std::string class_id_;
};

Object *_new_yac_() {
  return new Yet_Another_Identifier("yet another identifier");
}

typedef std::vector<std::pair<const std::string, Object *(*)()>> clas;

struct comp {
  explicit comp(std::string class_id) : _s(std::move(class_id)) {}
  bool operator()(std::pair<const std::string, Object *(*)()> const &p) const {
    return (p.first == _s);
  }

  std::string _s;
};

class Factory {
 public:
  void Register(const std::string &class_id, Object *(*instance_creator)()) {
    h.emplace_back(class_id, instance_creator);
  }
  Object *Create(const std::string &class_id) {
    auto bbb = h[0];
    auto i = std::find_if(h.begin(), h.end(), comp(class_id));
    return i->second();
  }
 private:
  clas h = {{"apple!", _new_apple_},
            {"list", _new_list_},
            {"yet another identifier", _new_yac_}};
};
