#include "monty.h"

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

/**
* op_rotl - moves top element to back, 2nd element becomes top
* @stack: data structure to be modified
* @line_number: used in error message
*/
void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *itr, *old;

	(void)line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	old = *stack;
	itr = (*stack)->next;
	itr->prev = NULL;
	*stack = itr;

	while (itr->next != NULL)
		itr = itr->next;
	itr->next = old;
	old->prev = itr;
	old->next = NULL;
}

/**
* op_rotr - moves back element to top, becomes new front
* @stack: data structure to be modified
* @line_number: used in error message
*/
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *itr;

	(void)line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	itr = (*stack)->next;

	while (itr->next != NULL)
		itr = itr->next;
	itr->prev->next = NULL;
	itr->prev = NULL;
	itr->next = *stack;
	(*stack)->prev = itr;
	*stack = itr;
}

