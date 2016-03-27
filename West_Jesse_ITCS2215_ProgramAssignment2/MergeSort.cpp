#include "MergeSort.h";

void MergeSort::mergeSort(int *arr, int left, int right)
{
	//Will hold the middle
	int mid;

	//Make sure low is less than high
	if (left < right)
	{
		//Assign the middle
		mid = (left + right) / 2;

		//Recursion
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		MergeSort::merge(arr, left, right, mid);
	}
}

void MergeSort::merge(int *arr, int left, int right, int mid)
{
	//Indexes
	int i, j, k;

	//Sizes for temp arrays
	const int n1 = mid - left + 1;
	const int n2 = right - mid;

	//Temp vectors
	std::vector<int> L(n1);
	std::vector<int> R(n2);



	//Copy data to temp vectors
	for (i = 0; i < n1; i++)
	{
		L.at(i) = arr[left + i];
	}

	for (j = 0; j < n2; j++)
	{
		R.at(j) = arr[mid + 1 + j];
	}

	//Merge the temp vectors back into arr

	i = 0; //Initial index of first subarray
	j = 0; //Initial index of second subarray
	k = left; //Initial index of merged subarray

	while (i < n1 && j < n2)
	{
		//Compare
		if (L.at(i) <= R.at(j))
		{
			arr[k] = L.at(i);
			i++;
		}
		else
		{
			arr[k] = R.at(j);
			j++;
		}
		k++;
	}

	//Copy the remaining elements of L if there are any
	while (i < n1)
	{
		arr[k] = L.at(i);
		i++;
		k++;
	}

	//Copy the remaining elements of R if there are any
	while (j < n2)
	{
		arr[k] = R.at(j);
		j++;
		k++;
	}
}
