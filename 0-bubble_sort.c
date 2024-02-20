#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - sort an array of integers in ascending order using
 * the bubble sort algorithm
 * @array: array of intgers to sort
 * @size: size of the array
 *
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
