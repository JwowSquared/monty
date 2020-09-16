#include "monty.h"

/**
* op_stack - toggles stack mode
* @stack: unused
* @line_number: unused
*/
void op_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	gm->stack = 1;
}

/**
* op_queue - toggles queue mode
* @stack: unused
* @line_number: unused
*/
void op_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	gm->stack = 0;
}
