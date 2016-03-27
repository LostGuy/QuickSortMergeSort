#pragma once
#include <utility>

class QuickSort
{
public:
	void static quickSort(int*, int, int);

private:
	int static partition(int*, const int, const int);

};
