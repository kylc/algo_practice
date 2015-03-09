#include <stdexcept>
#include <utility>

#include "tree.h"

template <typename T>
void action(const T& el) {
  std::cout << el << std::endl;
}

template <typename T>
void depthFirstTraverse(const TreeNode<T>& node) {
  // Pre-order traversal
  action(node.data);
  for(auto& child : node.children) {
    depthFirstTraverse(child);
  }
}

int main(int argc, char **argv) {
  // Build a tree of the factorization of some number
  unsigned int n = 9999;

  auto factors = factor(n);
  printTree(std::get<0>(factors));
  printTree(std::get<1>(factors));

  depthFirstTraverse(std::get<0>(factors));
  depthFirstTraverse(std::get<1>(factors));

  return 0;
}
