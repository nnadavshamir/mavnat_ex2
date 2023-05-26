#pragma once
#include <string>

class Node {
public:
	int priority;
	std::string data;
	int second_heap_index;
	
	Node() : priority(0), data(""), second_heap_index(0) { }
	Node(int _priority, std::string _data, int _linkedNodeIndex) : priority(_priority), data(_data), second_heap_index(_linkedNodeIndex) { }

	inline bool operator== (const Node& other) {
		return this->priority == other.priority && this->data == other.data && this->second_heap_index == other.second_heap_index;
	}

	inline operator std::string() const { return this->data; }
};

