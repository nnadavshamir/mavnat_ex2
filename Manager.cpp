#include "Manager.h"

Manager::Manager() : upperMaxHeap(Heap(true)), upperMinHeap(Heap(false)), lowerMaxHeap(Heap(true)), lowerMinHeap(Heap(false)) {
	upperMaxHeap.setSecondHeap(&upperMinHeap);
	upperMinHeap.setSecondHeap(&upperMaxHeap);
	lowerMaxHeap.setSecondHeap(&lowerMinHeap);
	lowerMinHeap.setSecondHeap(&lowerMaxHeap);
}

void Manager::fixUpperLowerIfNeeded()
{
	int upperSize = this->upperMaxHeap.getSize();
	int lowerSize = this->lowerMaxHeap.getSize();

	// Too many nodes in lower, one need to transfer to upper
	if (upperSize < lowerSize)
	{
		Node nodeToTransfer = this->lowerMaxHeap.DeleteExtreme();
		this->upperMaxHeap.Insert(nodeToTransfer.priority, nodeToTransfer.data);
		return;
	}

	// Too many node in upper, one need to transfer to lower
	if (upperSize > lowerSize + 1)
	{
		Node nodeToTransfer = this->upperMinHeap.DeleteExtreme();
		this->lowerMaxHeap.Insert(nodeToTransfer.priority, nodeToTransfer.data);
		return;
	}
}

void Manager::DeleteMax()
{
	this->lowerMinHeap.DeleteExtreme();
	this->fixUpperLowerIfNeeded();
}

void Manager::DeleteMin()
{
	this->lowerMinHeap.DeleteExtreme();
	this->fixUpperLowerIfNeeded();
}

void Manager::Insert(int priority, std::string data)
{
	this->upperMaxHeap.Insert(priority, data);
	this->fixUpperLowerIfNeeded();
}

bool Manager::IsEmpty()
{
	return this->upperMaxHeap.getSize() == 0;
}

void Manager::Max() {
	std::cout << this->upperMaxHeap.Extreme().data << std::endl;
}

void Manager::Median()
{
	std::cout << this->upperMinHeap.Extreme().data << std::endl;
}

void Manager::Min() {
	std::string minData = this->lowerMinHeap.getSize() > 0
		? this->lowerMinHeap.Extreme().data
		: this->upperMinHeap.Extreme().data;

	std::cout << minData << std::endl;
}

void Manager::MakeEmpty() {
	this->lowerMaxHeap.MakeEmpty();
	this->lowerMinHeap.MakeEmpty();
	this->upperMaxHeap.MakeEmpty();
	this->upperMinHeap.MakeEmpty();
}
