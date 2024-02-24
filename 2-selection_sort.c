#include "sort.h"

/*
 * selection_sort - sort an array or integers in ascending
 * order using selection sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (size == 1)
		return;
	for (i = 0; i < size - 1; i++)
	{
		size_t min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
