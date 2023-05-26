#include "Manager.h"

Manager::Manager() : upperMaxHeap(Heap(true)), upperMinHeap(Heap(false)), lowerMaxHeap(Heap(true)), lowerMinHeap(Heap(false)) {
	upperMaxHeap.setSecondHeap(&upperMinHeap);
	upperMinHeap.setSecondHeap(&upperMaxHeap);
	lowerMaxHeap.setSecondHeap(&lowerMinHeap);
	lowerMinHeap.setSecondHeap(&lowerMaxHeap);
}

void Manager::Max()
{
}

void Manager::DeleteMax()
{
}

void Manager::Min()
{
}

void Manager::DeleteMin()
{
}

void Manager::MakeEmpty()
{
}

void Manager::Insert(int priority, std::string value)
{
}

void Manager::Median()
{
}

bool Manager::IsEmpty()
{
	return false;
}
