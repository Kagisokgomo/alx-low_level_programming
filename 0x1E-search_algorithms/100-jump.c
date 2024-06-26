#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers using
 *               the Jump search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The first index where value is located,
 *         or -1 if value is not present in array or if array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
    size_t step = sqrt(size);
    size_t prev = 0;

    if (array == NULL || size == 0)
        return (-1);

    printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
    while (array[(step < size ? step : size) - 1] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", step, array[step]);
        prev = step;
        step += sqrt(size);
        if (prev >= size)
            return (-1);
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev, step);
    while (array[prev] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
        prev++;
        if (prev == (step < size ? step : size))
            return (-1);
    }

    if (array[prev] == value)
    {
        printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
        return (prev);
    }

    return (-1);
}
