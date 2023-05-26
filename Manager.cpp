#include "Manager.h"

Manager::Manager() : upperMaxHeap(Heap(true)), upperMinHeap(Heap(false)), lowerMaxHeap(Heap(true)), lowerMinHeap(Heap(false)) {
	upperMaxHeap.setSecondHeap(&upperMinHeap);
	upperMinHeap.setSecondHeap(&upperMaxHeap);
	lowerMaxHeap.setSecondHeap(&lowerMinHeap);
	lowerMinHeap.setSecondHeap(&lowerMaxHeap);
}

Node Manager::Max() {
	if (!this->upperMaxHeap.getSize()) {
		std::cout << "Heap is empty!" << std::endl;
		return Node();
	}

	return this->upperMaxHeap.Extreme();
}

Node Manager::Min() {
	if (!upperMinHeap.getSize()) {
		std::cout << "Heap is empty!" << std::endl;
		return Node();
	}

	else if (upperMinHeap.getSize() == 1)
		return this->upperMinHeap.Extreme();

	return this->lowerMinHeap.Extreme();
}

void Manager::MakeEmpty() {
	this->lowerMaxHeap.MakeEmpty();
	this->lowerMinHeap.MakeEmpty();
	this->upperMaxHeap.MakeEmpty();
	this->upperMinHeap.MakeEmpty();
}