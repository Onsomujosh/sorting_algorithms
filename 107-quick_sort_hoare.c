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
*This function implements the hoare partion scheme
*used in quick sort algorithm. To partition
*this function will take in an integer array
*its size and 2 indices low and high
*alternatively, you can use left and right
*/
int hoare_partition(int *array, size_t size, int low, int high);
/**
*hoare_partition - this function implements the hoare
*	partition on an array
*@array: This is the integer array to be sorted
*@size: this is the size of the array
*@low:  this refers to the left  most side of the arrray
*@high: this refers to the right most side of the array
*
*Return: This function returns the value of high.
*	this is the position of the pivot after partioning
*/
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot_integer, above_pivot, below_pivot;

	/*for this task, the take the pivot as the
	*most right sided element in the arrray*/
	pivot_integer = array[right];
	/*use 2 indices above_pivot and below_pivot
	*to move towards each other until they cross*/
	for (above_pivot = left - 1, below_pivot = right + 1;
		above_pivot < below_pivot;)
	{
		/*if above_pivot is less than below_pivot
		*swap the 2 elements and continue*/
		do {
			above_pivot++;
		} while (array[above_pivot] < pivot_integer);
		do {
			below_pivot--;
		} while (array[below_pivot] > pivot_integer);

		if (above_pivot < below_pivot)
		{
			swap_ints(array + above_pivot,
				array + below_pivot);
			print_array(array, size);
		}
	}

	/*return the value of the position of the
	*pivot element after partioning*/
	return (above_pivot);
}

/**Next, create a function that will implement the quicksort
*algorithm using recursion. This function will implement
*the hoare partitiion and quicksort techniques*/
void hoare_sort(int *array, size_t size, int left, int right);

/**
*hoare_sort - implements quicksort through recursion
*@array: the array to be sorted
*@size: the length of the array
*@left: left smost of the array
*@right: right most side of the array
*
*Return: Nothing. Void function
*/
void hoare_sort(int *array, size_t size, int left, int right)
{
	/*define an integer varaible that stores the position
	*of the pivot element after the hoare partion*/
	int partion_position;

	/*cfreate a base case for the recursion
	*check if the subarray on the left and
	*right contains more than one element
	*if, it doesn't, it means the subarray
	*can be further partioned and sorted*/
	if (right - left > 0)
	{
		/*call tyhe partition function to partion the subarray*/
		partion_position = hoare_partition(array, size, left, right);
		/*call the sort function to recursively sort the left subarray*/
		hoare_sort(array, size, left, partion_position - 1);
		/*call the sort function to recursively sort the right subarray*/
		hoare_sort(array, size, partion_position, right);
	}
}

/*implement the function that does the sorting*/
void quick_sort_hoare(int *array, size_t size);
/**
*quick_sort_hoare - this function sorts the array
*@array: the array to be sorted
*@size: this is the length of the array
*
*Return: Nothing
*/
void quick_sort_hoare(int *array, size_t size)
{
	/*Perform a base case to check for edge cases and return NULL*/
	if (array == NULL || size < 2)
		return;

	/*Call the function to perform the sorting*/
	hoare_sort(array, size, 0, size - 1);
}
