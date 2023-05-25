#pragma once
#include <iostream>

#define MAX_SIZE 100
#define NOT_SET -1

template <class T>
void swap(T& first, T& second) {
	T temp = first;
	first = second;
	second = temp;
}