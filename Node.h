#pragma once
#include <string>

class Node {
public:
	int priority;
	std::string data;
	int second_heap_index;
	
	Node(int _priority, std::string _data, int _linkedNodeIndex) : priority(_priority), data(_data), linkedNodeIndex(_linkedNodeIndex) { }
};

