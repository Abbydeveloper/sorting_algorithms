#include "sort.h"

/**
 * partition_quick_sort - partition a quick sort array
 * @array: array to partion
 * @lower: lower bound of partition
 * @upper: upper bound of partition
 *
 * Return: and integer that indicates the end of the partition
 */

int partition_quick_sort(int *array, int lower, int upper, size_t size)
{
	int pivot = array[lower];
	int start = lower - 1;
	int end = upper + 1;
	int tmp;

	while (1)
	{
		while (array[start] < pivot)
			start++;
		while (array[end] > pivot)
			end--;

		if (start >= end)
			return end;
		
		tmp = array[start];
		array[start] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}
}

/**
 * recursive_quick_sort - recursively sort through the array
 * @arr: array to sort
 * @lower: starting index
 * @upper: index to end at
 */

void recursive_quick_sort(int *arr, int lower, int upper, size_t size)
{
	int location;

	if (lower < upper)
	{
		location = partition_quick_sort(arr, lower, upper, size);
		recursive_quick_sort(arr, lower, location, size);
		recursive_quick_sort(arr, location + 1, upper, size);
	}

}
/**
 * quick_sort - sort an array of integers in ascending order using the quick sort algorithm
 * @array: array of integers to sort
 * @size: size of array
 *
 */

void quick_sort(int *array, size_t size)
{
	recursive_quick_sort(array, 0, size - 1, size);
}
