#include <iostream>
#include <utility>
#include <vector>

// N-ary tree data structure.
template <typename T>
class TreeNode {
public:
  explicit TreeNode(T data) : data(data) {
  }

  T data;
  std::vector<TreeNode> children;
};

template <typename T>
void printTree(const TreeNode<T>& root) {
  printTreeIndented(root, 0);
}

template <typename T>
void printTreeIndented(const TreeNode<T>& root, int indent) {
  for(int i = 0; i < indent; i++) {
    std::cout << "\t";
  }

  std::cout << root.data << std::endl;

  for(auto& child : root.children) {
    printTreeIndented(child, indent + 1);
  }
}

// Generate a tree from the factors of the given number. Useful for quickly
// generating a tree structure for testing.
std::pair<TreeNode<unsigned int>, TreeNode<unsigned int>> factor(unsigned int n) {
  // Count downward from n-1 to find the largest factor.
  for(unsigned int i = n - 1; i > 0; i--) {
    if(n % i == 0) {
      // Found a factor
      TreeNode<unsigned int> a(i);
      TreeNode<unsigned int> b(n / i);

      // Base case. If either multiple is 1, then the prime factorization has
      // been reached.
      if(a.data == 1 || b.data == 1) {
        return std::make_pair(a, b);
      }

      // Recursively factor a
      auto aFac = factor(a.data);
      a.children.push_back(std::get<0>(aFac));
      a.children.push_back(std::get<1>(aFac));

      // Recursively factor b
      auto bFac = factor(b.data);
      b.children.push_back(std::get<0>(bFac));
      b.children.push_back(std::get<1>(bFac));

      return std::make_pair(a, b);
    }
  }

  throw std::logic_error("Couldn't find a factor!");
}

