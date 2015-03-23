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
std::vector<T> quickSort(std::vector<T>& els) {
  std::vector<T> l, eq, g;

  if(els.size() <= 1) {
    return els;
  }

  // Select the pivot as the middle element.
  auto pivot = std::begin(els) + (els.size() / 2);

  // Split all elements into buckets full of elements 1) less than, 2) equal to,
  // or 3) greater than the pivot value.
  for(auto& el : els) {
    if(el < *pivot) {
      l.push_back(el);
    } else if(el > *pivot) {
      g.push_back(el);
    } else {
      eq.push_back(el);
    }
  }

  // Sort the elements less than and greater than.
  l = quickSort(l);
  g = quickSort(g);

  // Concatenate.
  std::vector<T> res;
  res.insert(std::end(res), std::begin(l), std::end(l));
  res.insert(std::end(res), std::begin(eq), std::end(eq));
  res.insert(std::end(res), std::begin(g), std::end(g));

  return res;
}

int main(int argc, char **argv) {
  std::vector<int> data {1, 5, 4, 8, 5, 3, 2, 5, 6, 3, -1};
  print(data);

  std::vector<int> sorted = quickSort(data);
  print(sorted);

  return 0;
}
