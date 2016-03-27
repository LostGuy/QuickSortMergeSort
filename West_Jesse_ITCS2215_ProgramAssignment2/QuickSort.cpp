#include "QuickSort.h";

void QuickSort::quickSort(int *arr, int left, int right)
{
	//Validate the size
	if (left >= right)
	{
		return;
	}

	//Partition
	int part = QuickSort::partition(arr, left, right);

	//Recursion
	QuickSort::quickSort(arr, left, part - 1);
	QuickSort::quickSort(arr, part + 1, right);
}

int QuickSort::partition(int *arr, const int left, const int right)
{
	const int mid = left + (right - left) / 2;
	const int pivot = arr[mid];

	//Move mid to the front
	std::swap(arr[mid], arr[left]);

	int i = left + 1;
	int j = right;

	//Go through the parts and swap if needed
	while (i <= j)
	{
		while (i <= j && arr[i] <= pivot) 
		{
			i++;
		}

		while (i <= j && arr[j] > pivot)
		{
			j--;
		}

		if (i < j)
		{
			std::swap(arr[i], arr[j]);
		}
	}

	std::swap(arr[i - 1], arr[left]);

	return i - 1;
}