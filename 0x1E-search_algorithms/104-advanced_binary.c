#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * print_subarray - Prints the subarray being searched
 * @array: Pointer to the first element of the subarray
 * @size: Number of elements in the subarray
 */
void print_subarray(int *array, size_t size)
{
    printf("Searching in array: ");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");
}

/**
 * advanced_binary_recursive - Recursive helper function for advanced_binary
 * @array: Pointer to the first element of the array
 * @low: Index of the first element of the subarray
 * @high: Index of the last element of the subarray
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of value in array, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
    if (low <= high)
    {
        print_subarray(array + low, high - low + 1);

        size_t mid = low + (high - low) / 2;

        if (array[mid] == value)
        {
            if (mid == low || array[mid - 1] != value)
                return mid;
            else
                return advanced_binary_recursive(array, low, mid, value);
        }
        else if (array[mid] < value)
        {
            return advanced_binary_recursive(array, mid + 1, high, value);
        }
        else
        {
            return advanced_binary_recursive(array, low, mid - 1, value);
        }
    }

    return -1;
}

/**
 * advanced_binary - Searches for a value in a sorted array using advanced binary search algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of value in array, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return -1;

    return advanced_binary_recursive(array, 0, size - 1, value);
}
