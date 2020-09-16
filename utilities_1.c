#include "monty.h"

/**
* isdigits - checks if a string is compromised of only digit characters
* @str: string to check
*
* Return: 1 if string is only digits, else 0
*/
int isdigits(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
