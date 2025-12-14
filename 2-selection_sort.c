#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - sorts an array of ints in ascending order using
 * selection sort
 * @array: pointer to the array
 * @size: size of array
 * Return: nothing/ void
 */

void selection_sort(int *array, size_t size)
{
	int min = 0;
	int temp, i, j;

	if (array == NULL)
		return;

	/*converting size to int so number can be negative*/
	for (i = 0; i <= (int)size - 1; i++)
	{
		/*set min number*/
		min = i;
		for (j = i; j <= (int)size - 1; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min == i)
			continue;

		/*do the swap*/
		temp = array[min];
		array[min] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}
