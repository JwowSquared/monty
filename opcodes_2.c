#include "monty.h"

/**
* op_pint - prints the value at the head of the stack
*/
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		print_error("L%d: cant pint, stack empty\n", &line_number, NULL, stack);

	printf("%d\n", (*stack)->n);
}
