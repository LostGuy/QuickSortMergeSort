#include <iostream>
#include <chrono>
#include "QuickSort.h"
#include "MergeSort.h"

void populateArray(int*, int);

int main()
{
	//Array to hold the numbers
	int numbers[500];

	//Holds the length of the array
	int numbersLength = sizeof(numbers) / sizeof(numbers[0]);

	/*-------------------QUICKSORT PART---------------------*/
	std::cout << "Creating the array for Quicksort" << std::endl;

	//Add the numbers to the array
	populateArray(numbers, numbersLength);
	
	std::cout << "Starting Quicksort" << std::endl;

	//Run quicksort while timing it
	auto time1 = std::chrono::high_resolution_clock::now();
	QuickSort::quickSort(numbers, 0, numbersLength - 1);
	auto time2 = std::chrono::high_resolution_clock::now();

	//Print the sorted numbers
	std::cout << "-------------------QUICKSORT PART---------------------" << std::endl;
	for (int i = 0; i < numbersLength; i++)
	{
		std::cout << numbers[i] << " ";
	}

	//Print the time elapsed to the screen
	std::cout << "\n\n" << "Quicksort took: " << std::chrono::duration_cast<std::chrono::milliseconds>(time2 - time1).count() << " milliseconds\n\n";







	/*-------------------MERGESORT PART---------------------*/
	std::cout << "Creating the array for Mergesort" << std::endl;

	//Replace the sorted array with random numbers
	populateArray(numbers, numbersLength);

	//Run the algorithm and time it
	time1 = std::chrono::high_resolution_clock::now();
	MergeSort::mergeSort(numbers, 0, numbersLength - 1);
	time2 = std::chrono::high_resolution_clock::now();

	//Print the sorted numbers
	std::cout << "-------------------MERGESORT PART---------------------" << std::endl;
	for (int i = 0; i < numbersLength; i++)
	{
		std::cout << numbers[i] << " ";
	}

	//Print the time elapsed to the screen
	std::cout << "\n\n" << "Mergesort took: " << std::chrono::duration_cast<std::chrono::milliseconds>(time2 - time1).count() << " milliseconds\n";

	//Pause the system so the results stay on screen
	system("pause");
	return 0;
}

//Inserts random numbers (1-100) to an array
void populateArray(int *arr, int length)
{
	//Add random numbers (1-100) to the array
	for (int i = 0; i < length; i++)
	{
		//Assing the element a random number between 1 and 100
		arr[i] = std::rand() % 100 + 1;
	}
}