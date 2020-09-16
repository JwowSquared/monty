#include "monty.h"

/**
* op_add - combines the top 2 elements of the stack
* @stack: data structure to modify
* @line_number: used in error message
*/
void op_add(stack_t **stack, unsigned int line_number)
{
	int old;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_error("L%u: can't add, stack too short\n", &line_number, NULL, stack);

	old = (*stack)->n;
	op_pop(stack, line_number);
	(*stack)->n += old;
}

/**
* op_sub - combines the top 2 stack elements with subtraction
* @stack: data structure to modify
* @line_number: used in error message
*/
void op_sub(stack_t **stack, unsigned int line_number)
{
	int old;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_error("L%u: can't sub, stack too short\n", &line_number, NULL, stack);

	old = (*stack)->n;
	op_pop(stack, line_number);
	(*stack)->n -= old;
}

/**
* op_div - combines the top 2 stack elements with division
* @stack: data structure to modify
* @line_number: used in error message
*/
void op_div(stack_t **stack, unsigned int line_number)
{
	int old;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_error("L%u: can't div, stack too short\n", &line_number, NULL, stack);

	old = (*stack)->n;
	if (!old)
		print_error("L%u: division by zero\n", &line_number, NULL, stack);

	op_pop(stack, line_number);
	(*stack)->n /= old;
}

/**
* op_mul - combines the top 2 stack elements with multiplication
* @stack: data structure to modify
* @line_number: used in error message
*/
void op_mul(stack_t **stack, unsigned int line_number)
{
	int old;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_error("L%u: can't mul, stack too short\n", &line_number, NULL, stack);

	old = (*stack)->n;
	op_pop(stack, line_number);
	(*stack)->n *= old;
}

/**
* op_mod - combines the top 2 stack elements with modulus
* @stack: data structure to modify
* @line_number: used in error message
*/
void op_mod(stack_t **stack, unsigned int line_number)
{
	int old;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_error("L%u: can't mod, stack too short\n", &line_number, NULL, stack);

	old = (*stack)->n;
	if (!old)
		print_error("L%u: division by zero\n", &line_number, NULL, stack);

	op_pop(stack, line_number);
	(*stack)->n %= old;
}
