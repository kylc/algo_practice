#include <queue>
#include <stdexcept>
#include <utility>

#include "tree.h"

template <typename T>
void action(const T& el) {
  std::cout << el << std::endl;
}

template <typename T>
void breadthFirstSearch(const TreeNode<T>& node) {
  std::queue<const TreeNode<T> *> q;

  q.push(&node);
  while(!q.empty()) {
    auto el = q.front();
    q.pop();

    action(el->data);

    for(auto& child : el->children) {
      q.push(&child);
    }
  }
}

int main(int argc, char **argv) {
  // Build a tree of the factorization of some number
  unsigned int n = 9999;

  auto factors = factor(n);
  printTree(std::get<0>(factors));
  printTree(std::get<1>(factors));

  breadthFirstSearch(std::get<0>(factors));
  breadthFirstSearch(std::get<1>(factors));

  return 0;
}
