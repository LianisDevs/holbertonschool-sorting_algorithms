#include <stdio.h>
#include <stdbool.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of ints in ascending order
 * using buble sort algorith
 * @array: pointer to array to sort
 * @size: size of array
 * Return: nothing/ void
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i = 0, j;
	bool swapped = false;

	do {
		swapped = false;

		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				/*doing the swap so array[j] < array[+1]*/
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/*updating sweapped to true*/
				swapped = true;

				print_array(array, size);
			}
		}
		/*increment i*/
		i++;
	} while (swapped);
}

