#include <iostream>
#include "Heap.h"

int main() {
    Heap max_heap = Heap(true);
    Heap min_heap = Heap(false);

    max_heap.setSecondHeap(&min_heap);
    min_heap.setSecondHeap(&max_heap);

    max_heap.Insert(3, "Eliya");
    max_heap.Insert(1, "Dani");
    max_heap.Insert(2, "Maya");
    
    max_heap.DeleteExtreme();

    for (int i = 0; i < min_heap.getSize(); i++)
        std::cout << min_heap.getHeap()[i].data << std::endl;
}