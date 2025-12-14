#include <stdio.h>
#include "sort.h"

void sort_it(int *array, int low, int high, size_t size);
int partition_it(int *array, int low, int high, size_t size);
void swap_it(int *a, int *b);
/**
 * quick_sort - sorts an array of ints in ascending order using
 * quick sort algorithm
 * @array: pointer to array to sort
 * @size: size of array
 * Return: nothing/ void
 */

void quick_sort(int *array, size_t size)
{
	sort_it(array, 0, (int)size - 1, size);
}

/**
 * sort_it - recursively sorts through the array calling
 * partition if low < high
 * @array: pointer to array
 * @low: index to the low value
 * @high: index to the high value
 * @size: size of the array
 * Return: nothing/ void
 */
void sort_it(int *array, int low, int high, size_t size)
{
	int index;

	if (low < high)
	{
		index = partition_it(array, low, high, size);

		sort_it(array, low, index - 1, size);
		sort_it(array, index + 1, high, size);
	}
}

/**
 * partition_it - partitions the array with low on the left and high
 * on the right
 * @array: pointer to the array
 * @low: index to the low value
 * @high: index to the high value
 * @size: size of the array
 * Return: nothing/ void
 */
int partition_it(int *array, int low, int high, size_t size)
{
	int position = array[high];
	int i = (low - 1);
	int j = low;

	for (; j <= high - 1; j++)
	{
		if (array[j] <= position)
		{
			i++;
			if (i != j)
			{
				swap_it(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap_it(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * swap_it - swaps the data in a and b
 * @a: address to element a
 * @b: address to element b
 * Return: nothing/ void
 */
void swap_it(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
