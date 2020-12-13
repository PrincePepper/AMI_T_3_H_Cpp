#pragma once
#include <unordered_map>

template<class Vertex>
class BfsVisitor {
 public:
  BfsVisitor() {
    p = new std::unordered_map<Vertex, Vertex>();
    v = NULL;
  }
  void ExamineVertex(const Vertex &vertex) {
    if (v == NULL) {
      v = new Vertex(vertex);
      return;
    }
    *v = vertex;
  }
  void DiscoverVertex(const Vertex &vertex) {
    if (v == NULL) {
      p->insert({vertex, vertex});
      return;
    }
    p->insert({vertex, *v});
  }

  size_t DistanceTo(const Vertex &target) const {
    size_t path = 0;
    for (Vertex i = target; i != p->at(i); i = p->at(i))
      path++;
    return path;
  }
  Vertex Parent(const Vertex &vertex) const {
    return p->at(vertex);
  }

  ~BfsVisitor() {
    delete v;
    delete p;
  }

 private:
  Vertex *v;

  std::unordered_map<Vertex, Vertex> *p;
};
