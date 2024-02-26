#include "sort.h"

/**
 * swap_digits - swap two digits within an array
 * @array: array to swap items in
 * @i: index of the first digit to swap
 * @j: index of the second digit to swap
 *
 * Return: Nothing
 */

void swap_digits(int *array, int i, int j)
{
	int tmp;

	if (array == NULL)
		return;
	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}


/**
 * partition_quick_sort - partition a quick sort array
 * @array: array to partion
 * @lower: lower bound of partition
 * @upper: upper bound of partition
 * @size: size of array
 *
 * Return: an integer that indicates the end of the partition
 */

int partition_quick_sort(int *array, int lower, int upper, size_t size)
{
	int pivot = array[upper];
	int start = lower;
	int end;

	for (end = lower; end < upper; end++)
	{
		if (array[end] <= pivot)
		{
			if (start != end)
			{
				swap_digits(array, start, end);
				print_array(array, size);
			}
			start++;
		}
	}
	if (start < upper)
	{
		swap_digits(array, start, upper);
		print_array(array, size);
	}
	return (start);
}

/**
 * recursive_quick_sort - recursively sort through the array
 * @arr: array to sort
 * @lower: starting index
 * @upper: index to end at
 * @size: size of array
 */

void recursive_quick_sort(int *arr, int lower, int upper, size_t size)
{
	if (lower < upper)
	{
		int location = partition_quick_sort(arr, lower, upper, size);

		recursive_quick_sort(arr, lower, location - 1, size);
		recursive_quick_sort(arr, location + 1, upper, size);
	}

}
/**
 * quick_sort - sort an array of integers in ascending order
 * using the quick sort algorithm
 * @array: array of integers to sort
 * @size: size of array
 *
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	recursive_quick_sort(array, 0, size - 1, size);
}
