#include <iostream>
#include <vector>

template <typename T>
void print(const std::vector<T>& els) {
  for(auto& el : els) {
    std::cout << el << ", ";
  }
  std::cout << std::endl;
}

template <typename T>
std::vector<T> merge(std::vector<T>& l, std::vector<T>& r) {
  std::vector<T> res;
  res.reserve(l.size() + r.size());

  auto lit = std::begin(l);
  auto rit = std::begin(r);

  // Merge until the end of either list.
  while(lit < std::end(l) && rit < std::end(r)) {
    if(*lit < *rit) {
      res.push_back(*lit);
      lit++;
    } else {
      res.push_back(*rit);
      rit++;
    }
  }

  // Add remaining elements from the left list (if any).
  while(lit < std::end(l)) {
    res.push_back(*lit);
    lit++;
  }

  // Add remaining elements from the right list (if any).
  while(rit < std::end(r)) {
    res.push_back(*rit);
    rit++;
  }

  return res;
}

template <typename T>
std::vector<T> mergeSort(std::vector<T>& els) {
  // Base case. Single item is already sorted.
  if(els.size() == 1) {
    return els;
  }

  // Find the middle of the vector.
  auto middle = std::begin(els) + (els.size() / 2);

  std::vector<T> l(std::begin(els), middle);
  std::vector<T> r(middle, std::end(els));

  // Sort both halves.
  l = mergeSort(l);
  r = mergeSort(r);

  // Merge them together.
  return merge(l, r);
}

int main(int argc, char **argv) {
  std::vector<int> data {1, 5, 4, 8, 5, 3, 2, 5, 6, 3, -1};
  print(data);

  std::vector<int> sorted = mergeSort(data);
  print(sorted);

  return 0;
}
