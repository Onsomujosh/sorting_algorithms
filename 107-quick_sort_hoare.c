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
