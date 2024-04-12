#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array using binary search algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value in the array, or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
    size_t low = 0, high = size - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        printf("Searching in array: ");
        for (size_t i = low; i <= high; i++)
        {
            printf("%d", array[i]);
            if (i < high)
                printf(", ");
        }
        printf("\n");

        if (array[mid] == value)
            return mid;

        if (array[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

/**
 * exponential_search - Searches for a value in a sorted array using Exponential search algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of value in array, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return -1;

    size_t bound = 1;

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", bound / 2, bound >= size ? size - 1 : bound);

    size_t low = bound / 2, high = bound >= size ? size - 1 : bound;

    return binary_search(array + low, high - low + 1, value) + low;
}
