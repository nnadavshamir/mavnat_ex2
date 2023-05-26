#include "Manager.h"

Manager::Manager() : upperMaxHeap(Heap(true)), upperMinHeap(Heap(false)), lowerMaxHeap(Heap(true)), lowerMinHeap(Heap(false)) {
	upperMaxHeap.setSecondHeap(&upperMinHeap);
	upperMinHeap.setSecondHeap(&upperMaxHeap);
	lowerMaxHeap.setSecondHeap(&lowerMinHeap);
	lowerMinHeap.setSecondHeap(&lowerMaxHeap);
}


void printNode(Node node) {
	std::cout << node.priority << " " << node.data << std::endl;
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
	printNode(this->upperMaxHeap.DeleteExtreme());
	this->fixUpperLowerIfNeeded();
}

void Manager::DeleteMin()
{
	printNode(this->lowerMinHeap.getSize() > 0
		? this->lowerMinHeap.DeleteExtreme()
		: this->upperMinHeap.DeleteExtreme());
	this->fixUpperLowerIfNeeded();
}

void Manager::Insert(int priority, std::string data)
{
	// If priority smaller than lower max insert to lower heap
	if (!this->lowerMaxHeap.IsEmpty() && this->lowerMaxHeap.Extreme().priority > priority)
	{
		this->lowerMaxHeap.Insert(priority, data);
	}
	else
	{
		this->upperMaxHeap.Insert(priority, data);
	}

	this->fixUpperLowerIfNeeded();
}

bool Manager::IsEmpty()
{
	return this->upperMaxHeap.getSize() == 0;
}

void Manager::Max() {
	printNode(this->upperMaxHeap.Extreme());
}

void Manager::Median()
{
	if (this->upperMinHeap.getSize() == this->lowerMinHeap.getSize())
	{
		printNode(this->lowerMaxHeap.Extreme());
	}
	else
	{
		printNode(this->upperMinHeap.Extreme());
	}
}

void Manager::Min() {
	printNode(this->lowerMinHeap.getSize() > 0
		? this->lowerMinHeap.Extreme()
		: this->upperMinHeap.Extreme());
}

void Manager::MakeEmpty() {
	this->lowerMaxHeap.MakeEmpty();
	this->lowerMinHeap.MakeEmpty();
	this->upperMaxHeap.MakeEmpty();
	this->upperMinHeap.MakeEmpty();
}
