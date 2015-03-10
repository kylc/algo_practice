CXX=clang++
CXXFLAGS=-Wall -std=c++14

breadth_first_search: breadth_first_search.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

depth_first_search: depth_first_search.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
