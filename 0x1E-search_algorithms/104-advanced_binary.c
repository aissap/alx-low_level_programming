#include "search_algos.h"
#include <stdio.h>

/**
 * advanced_binary_recursive - Searches for a value in an array.
 * @array: Pointer to the first element of the array to search.
 * @left: Starting index of the subarray to search.
 * @right: Ending index of the subarray to search.
 * @value: Value to search for.
 *
 * Return: Index of the first occurrence of the value in the array,
 *         or -1 if the value is not present.
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	if (left <= right)
	{
		size_t i;
		size_t mid = left + (right - left) / 2;

		printf("Searching in array: ");
		for (i = left; i < right; ++i)
			printf("%d, ", array[i]);
		printf("%d\n", array[right]);

		if (array[mid] == value)
		{
			if (mid == left || array[mid - 1] != value)
				return (mid);
			else
				return (advanced_binary_recursive(array, left, mid, value));
		}

		if (array[mid] < value)
			return (advanced_binary_recursive(array, mid + 1, right, value));
		else
			return (advanced_binary_recursive(array, left, mid, value));
	}

	return (-1);
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array to search.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: Index of the first occurrence of the value in the array,
 *         or -1 if the value is not present.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
