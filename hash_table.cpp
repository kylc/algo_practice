#include <algorithm>
#include <experimental/optional>
#include <iostream>
#include <utility>
#include <vector>

template <typename K, typename V>
class HashTable {
public:
  /**
   * Create a new hash table with the given number of buckets initially
   * reserved.
   */
  explicit HashTable(int size) {
    // Don't need to specify an initialization value because these buckets
    // should never be read until they are overwritten with real data.
    buckets.resize(size);
  }

  void insert(K k, V v) {
    const std::size_t idx = index(k);

    // Grab the bucket and place this element at the end.
    std::vector<std::pair<K, V>>& bucket = buckets[idx];
    bucket.push_back(std::make_pair(k, v));

    numElements++;
  }

  std::experimental::optional<V> lookup(K k) const {
    const std::size_t idx = index(k);

    // Find the bucket for this index. O(1).
    const std::vector<std::pair<K, V>>& bucket = buckets[idx];

    // Find the element with the  bucket for this key. O(1) average, O(n) worse
    // case.
    for(const auto& el : bucket) {
      if(std::get<0>(el) == k) {
        return std::experimental::make_optional(std::get<1>(el));
      }
    }

    return std::experimental::nullopt;
  }

  void remove(K k) {
    const std::size_t idx = index(k);

    // Find the bucket for this index. O(1).
    std::vector<std::pair<K, V>>& bucket = buckets[idx];

    // Erase all elements in the bucket that match the given key. O(1) average,
    // O(n) worst case.
    bucket.erase(
      std::remove_if(
        std::begin(bucket),
        std::end(bucket),
        [&](auto& el) {
          return std::get<0>(el) == k;
        }
      )
    );
  }

  float loadFactor() const {
    if(buckets.size() == 0) {
      return 1.0;
    }

    return (float) numElements / (float) buckets.size();
  }

private:
  /**
   * Compute the index into the buckets vector for a key.
   *
   * NOTE: These indices are only valid for a constant buckets vector size.
   */
  std::size_t index(K k) const {
    std::hash<K> hashFunc;

    return hashFunc(k) % buckets.size();
  }

  std::vector<std::vector<std::pair<K, V>>> buckets;

  // For load factor
  std::size_t numElements;
};

int main(int argc, char **argv) {
  HashTable<int, int> table(10);

  table.insert(50, 25);
  table.insert(51, 22);
  table.insert(52, 23);
  table.insert(53, 24);
  std::cout << table.lookup(50).value_or(0) << std::endl;

  table.remove(50);
  std::cout << table.lookup(50).value_or(0) << std::endl;

  std::cout << table.lookup(52).value_or(0) << std::endl;
}
