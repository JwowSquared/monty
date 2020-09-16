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
	{"#", &op_nop},
	{"nop", &op_nop},
	{"push", &op_push},
	{"pall", &op_pall},
	{"pint", &op_pint},
	{"pop", &op_pop},
	{"swap", &op_swap},
	{"add", &op_add},
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
* op_push - handles opcode push
* @stack: stack data structure to be modified
* @line_number: used when printing an error message
*/
void op_push(stack_t **stack, unsigned int line_number)
{
	char *val = *gm->val;
	int i;
	stack_t *new;

	(void)line_number;
	while (*val == ' ')
		val++;
	for (i = 0; val[i] != ' ' && val[i] != '\n' && val[i];)
		i++;
	val[i] = '\0';

	if (!isdigits(val))
		print_error("L%u: usage: push integer\n", &line_number, NULL, stack);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		print_error("Error: malloc failed\n", NULL, NULL, stack);

	new->prev = NULL;
	new->next = *stack;
	new->n = atoi(val);
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
* op_nop - handles any opcodes that do absolutely NOTHING
* @stack: stack data structure to be modified
* @line_number: used when printing an error message
*/
void op_nop(stack_t **stack, unsigned int line_number)
{
	/* this doesnt do anything */
	(void)stack;
	(void)line_number;
}

/**
* op_pall - handles the opcode pall
* @stack: stack data structure to be modified
* @line_number: used when printing an error message
*/
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *itr = *stack;

	(void)line_number;
	while (itr != NULL)
	{
		printf("%d\n", itr->n);
		itr = itr->next;
	}
}
