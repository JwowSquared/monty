#include "monty.h"

/**
* op_pint - prints the value at the head of the stack
*/
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		print_error("L%d: can't pint, stack empty\n", &line_number, NULL, stack);

	printf("%d\n", (*stack)->n);
}

/**
* op_pop - removes top most element of the stack
*/
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *itr;

	if (stack == NULL || *stack == NULL)
		print_error("L%d: can't pop an empty stack\n", &line_number, NULL, stack);

	itr = *stack;
	*stack = (*stack)->next;
	free(itr);
	if (*stack != NULL)
		(*stack)->prev = NULL;
}

/**
* op_swap - switches the positions of the top 2 elements of the stack
*/
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *left, *right;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_error("L%d: can't swap, stack too short\n", &line_number, NULL, stack);

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
