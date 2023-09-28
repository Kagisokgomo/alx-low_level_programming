#include "main.h"

/**
 * _isdigit - Checks for lowercase character
 * @c:The character to be checked
 * Return: 1 for uppercase character or 0 for anything else
 */

int _isdigit(int c)

{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
