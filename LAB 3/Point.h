#pragma once

#include <ostream>

class Point {
 public:

  Point(int x, int y) : x(x), y(y) {}

  Point() = default;

  bool operator==(const Point other) const {
    return this->x == other.x && this->y == other.y;
  }

  bool operator!=(const Point &other) const {
    return !(*this == other);
  }

  bool operator<(const Point other) const {
    return this->x < other.x && this->y < other.y;
  }

  Point operator=(const Point &other) {
    x = other.x;
    y = other.y;
    return *this;
  }

  int x;

  int y;
};

struct CoordsHash {
  std::size_t operator()(const Point &coords) const {
    return std::hash<int>()(coords.x) ^ (std::hash<int>()(coords.y) << 1);
  }
};

std::ostream &operator<<(std::ostream &stream, const Point coords) {
  return stream << coords.x << ' ' << coords.y;
}