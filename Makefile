CXX=clang++
CXXFLAGS=-Wall -std=c++14

breadth_first_search: breadth_first_search.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

depth_first_search: depth_first_search.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

merge_sort: merge_sort.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

quick_sort: quick_sort.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

hash_table: hash_table.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
