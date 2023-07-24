#include <stdlib.h>
#include "sort.h"

/**
*swap_ints - Swaps two elements in an array.
*@a: The first element to swap.
*@b: The second element to swap.
*/
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*This part of the code implements the critical step of*/
/*merging the 2 bitonic sequences into one bitonic sequence*/
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char order);
/**
*bitonic_merge - this function merges 2 bitonic sequences to one
*@array: this is the array to be sorted
*@size: this refers to the size of the array
*@start: this is the starting index of the currenct sub-sequence
*@seq: refers to the size of the subarray
*@order: this is a variable of the type char. it defines
*	the sorting order
*
*Return: The function is a void function
*/
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char order)
{
	size_t i, skip = seq / 2;

	/*If the size of the current subarray (seq) is greater*/
	/*than 1, it means the subarray can be further divide*/
	/*and merged*/
	if (seq > 1)
	{
		/*The function iterates through the elements of*/
		/*the first half of the subarray (from start to*/
		/*start + skip - 1)*/
		for (i = start; i < start + skip; i++)
		{
			/*It compares the elements from both halves of the subarray*/
			/*and performs a swap if necessary, based on the specified*/
			/*sorting order (flow)*/
			if ((order == UP && array[i] > array[i + skip]) ||
			    (order == DOWN && array[i] < array[i + skip]))
				swap_ints(array + i, array + i + skip);
		}
		/*After the swapping, the function recursively calls itself twice*/
		/*to continue merging the subarrays until the base case is reached.*/
		bitonic_merge(array, size, start, skip, order);
		bitonic_merge(array, size, start + skip, skip, order);
	}
}

void bitonic_seq(int *array, size_t size, size_t start,
		size_t seq, char order);
/*This function implements the recursive part*/
/*of the bitonic algorithm*/
/**
*bitonic_seq - this function creates a bitonic sequence
*@array: the array to be sorted
*@size: thi refers to the size of the array
*@start: refers to the starting index of the current subarray
*@seq: this is the size of the current subarray
*@order: this is a character that represents the sorting order
*
*Return: Returns nothing. This is a void function
*/
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char order)
{
	size_t subarray = seq / 2;
	char *string;

	if (order == UP)
	{
		string = "UP";
	}
	else
	{
		string = "DOWN";
	}
	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, string);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, subarray, UP);
		bitonic_seq(array, size, start + subarray, subarray, DOWN);
		bitonic_merge(array, size, start, seq, order);

		printf("Result [%lu/%lu] (%s):\n", seq, size, string);
		print_array(array + start, seq);
	}
}

/*sort the array of integers in ascending order*/
/*using the bitonic_seq function*/
/*it constructs a bitonic sequence by*/
/*recursively dividing and merging the array*/
void bitonic_sort(int *array, size_t size);
/**
*bitonic_sort - this function sorts the array in asending order
*@array: refers to the array to be sorted
*@size: refers to the size of the array
*
*Return: Nothing. This is a void function
*/
void bitonic_sort(int *array, size_t size)
{
	/*It checks if the input array array is NULL or*/
	/*if the size of the array is less than 2*/
	/*If either of these conditions is true, it means the array*/
	/*is already sorted or cannot be sorted, so the function*/
	/*returns early without performing any sorting*/
	if (array == NULL || size < 2)
	{
		return;
	}
	/*call the bitonic function  to sort in ascending order*/
	bitonic_seq(array, size, 0, size, UP);
}
