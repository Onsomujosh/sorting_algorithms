#include "sort.h"

/**
 * swap_ints - Swaps two elements in an array.
 * @a: The first element to swap.
 * @b: The second element to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
*shell_sort - sorts an array of integers in ascending order
*	using the shell sort algorithm
*@array: this refers to the array to be sorted
*@size: refers to the size of the array
*
*Return: This is is a void function
*/
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	/*if array is less than 2, it's already sorted*/
	if (array == NULL || size < 2)
	{
		return;
	}
	/*else use the Knutt's sequence*/
	for (gap = 1; gap < (size / 3);)
	{
		gap = gap * 3 + 1;
	}
	/*perfom the shell sort. Remember in it's worst case*/
	/*The shell sort is an inserton algorithm*/
	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
			{
				swap_ints(array + j, array + (j - gap));
			}
		}
		print_array(array, size);
	}
}
