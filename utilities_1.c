#include "monty.h"

/**
* match_op - matches given opcode with its function
* @op: opcode to match with a given
* @stack: parameter to pass to i_t.f
* @line_number: parameter to pass to i_t.f
*
* Return: 1 if match found, else 0
*/
int match_op(char *op, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t i_t[] = {
	{"\0", &op_nop},
	{"nop", &op_nop},
	{"push", &op_push},
	{"pall", &op_pall},
	{"pint", &op_pint},
	{"pop", &op_pop},
	{"swap", &op_swap},
	{"add", &op_add},
	{"sub", &op_sub},
	{"div", &op_div},
	{"mul", &op_mul},
	{"mod", &op_mod},
	{"pchar", &op_pchar},
	{"pstr", &op_pstr},
	{"rotl", &op_rotl},
	{"rotr", &op_rotr},
	{"stack", &op_stack},
	{"queue", &op_queue},
	{NULL, NULL},
	};

	while (i_t[i].f != NULL)
	{
		if (!strcmp(i_t[i].opcode, op))
		{
			i_t[i].f(stack, line_number);
			return (1);
		}
		i++;
	}

	return (0);
}

/**
* isdigits - checks if a string is compromised of only digit characters
* @str: string to check
*
* Return: 1 if string is only digits, else 0
*/
int isdigits(char *str)
{
	int i = 0;

	if (str[i] == '\0')
		return (0);

	if (str[i] == '-')
		i++;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}

	return (1);
}
