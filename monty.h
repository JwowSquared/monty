#ifndef _MONTY_
#define _MONTY_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>

/**
* struct global_memory - pairs all needed globals into 1 variable
* @val: pointer to integer value associated with push
* @buf: pointer to buffer used to read lines from the input file
* @input: pointer to file used for input
*
* Description: This just kinda seems silly. Only used in cleanup()
* and op_push()
*/
typedef struct global_memory
{
	char **val;
	char **buf;
	FILE **input;
} g_m;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Utilities */
int isdigits(char *);

/* Driver functions */
int match_op(char *, stack_t **, unsigned int);
void free_stack(stack_t **);
void cleanup(stack_t **);
void print_error(char *, unsigned int *, char *, stack_t **);

/* Mandatory opcodes */
void op_push(stack_t **, unsigned int);
void op_pall(stack_t **, unsigned int);
void op_pint(stack_t **, unsigned int);
void op_pop(stack_t **, unsigned int);
void op_swap(stack_t **, unsigned int);
void op_add(stack_t **, unsigned int);
void op_nop(stack_t **, unsigned int);

/* Advanced opcodes */
void op_sub(stack_t **, unsigned int);
void op_div(stack_t **, unsigned int);
void op_mul(stack_t **, unsigned int);
void op_mod(stack_t **, unsigned int);
void op_comment(stack_t **, unsigned int);
void op_pchar(stack_t **, unsigned int);
void op_pstr(stack_t **, unsigned int);
void op_rotl(stack_t **, unsigned int);
void op_rotr(stack_t **, unsigned int);
void op_stack(stack_t **, unsigned int);
void op_queue(stack_t **, unsigned int);

#endif /* _MONTY_ */
