#include "monty.h"

/**
* op_pint - prints the value at the head of the stack
* @stack: data structure to print from
* @line_number: used in error message
*/
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		print_error("L%u: can't pint, stack empty\n", &line_number, NULL, stack);

	printf("%d\n", (*stack)->n);
}

/**
* op_pop - removes top most element of the stack
* @stack: data structure to remove from
* @line_number: used in error message
*/
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *itr;

	if (stack == NULL || *stack == NULL)
		print_error("L%u: can't pop an empty stack\n", &line_number, NULL, stack);

	itr = *stack;
	*stack = (*stack)->next;
	free(itr);
	if (*stack != NULL)
		(*stack)->prev = NULL;
}

/**
* op_swap - switches the positions of the top 2 elements of the stack
* @stack: data structure to modify
* @line_number: used in error message
*/
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *left, *right;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_error("L%u: can't swap, stack too short\n", &line_number, NULL, stack);

	left = *stack;
	right = left->next;

	left->prev = left->next;
	left->next = right->next;
	if (right->next != NULL)
		right->next->prev = left;
	right->next = left;
	right->prev = NULL;

	*stack = right;
}

/**
* op_pchar - prints the top element of a stack as a char
* @stack: data structure to modify
* @line_number: used in error message
*/
void op_pchar(stack_t **stack, unsigned int line_number)
{
	int c;

	if (stack == NULL || *stack == NULL)
		print_error("L%u: can't pchar, stack empty\n", &line_number, NULL, stack);

	c = (*stack)->n;
	if (c < ' ' || c > '~')
		print_error("L%u: can't pchar, value out of range\n", &line_number, NULL, stack);

	printf("%c\n", c);
}

/**
* op_pstr - prints a string starting at the top stack element
* @stack: data structure to modify
* @line_number: used in error message
*/
void op_pstr(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
