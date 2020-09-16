#include "monty.h"

/* Global Declaration */
g_m *gm = NULL;

/**
* main - main controller for the monty program
* @ac: argc
* @av: argv
*
* Return: 0 if no errors encountered, else EXIT_FAILURE
*/
int main(int ac, char **av)
{
	char *op, *buf = NULL, *val = NULL;
	unsigned int i, ln = 1;
	size_t buf_s = 1024;
	stack_t *stack = NULL;
	FILE *input = NULL;

	if (ac != 2)
		print_error("USAGE: monty file\n", NULL, NULL, NULL);
	input = fopen(av[1], "r");
	if (input == NULL)
		print_error("Error: Can't open file %s\n", NULL, av[1], NULL);

	gm = malloc(sizeof(g_m));
	buf = malloc(sizeof(char) * buf_s);
	if (gm == NULL || buf == NULL)
		print_error("Error: malloc failed\n", NULL, NULL, NULL);
	gm->stack = 1;
	gm->buf = &buf;
	gm->val = &val;
	gm->input = &input;

	while (fgets(buf, buf_s, input) != NULL)
	{
		op = buf;
		while (*op == ' ')
			op++;
		if (*op != '#')
		{
			for (i = 0; op[i] != ' ' && op[i] != '\n' && op[i];)
				i++;
			op[i] = '\0';
			val = &op[i + 1];
			if (!match_op(op, &stack, ln))
				print_error("L%u: unknown instruction %s\n", &ln, op, &stack);
		}
		ln++;
		memset(buf, 0, buf_s);
	}
	cleanup(&stack);
	exit(EXIT_SUCCESS);
}

/**
* print_error - prints an error message, cleans up memory, and exits
* @prompt: format string for printf with error specific message
* @ln: pointer to line number, optional
* @op: pointer to attempted opcode, optional
* @stack: pointer to stack used in cleanup() call
*/
void print_error(char *prompt, unsigned int *ln, char *op, stack_t **stack)
{
	if (ln == NULL && op == NULL)
		fprintf(stderr, "%s", prompt);
	else if (op == NULL)
		fprintf(stderr, prompt, *ln);
	else if (ln == NULL)
		fprintf(stderr, prompt, op);
	else
		fprintf(stderr, prompt, *ln, op);

	cleanup(stack);
	exit(EXIT_FAILURE);
}

/**
* cleanup - frees stack, buf, and closes input
* @stack: pointer to stack data structure to free
*/
void cleanup(stack_t **stack)
{
	free_stack(stack);
	if (gm != NULL)
	{
		if (*gm->buf != NULL)
			free(*gm->buf);
		if (*gm->input != NULL)
			fclose(*gm->input);
		free(gm);
	}
}

/**
* free_stack - frees the stack
* @stack: pointer to stack data structure to free
*/
void free_stack(stack_t **stack)
{
	stack_t *itr;

	if (stack == NULL || *stack == NULL)
		return;

	while (*stack != NULL)
	{
		itr = *stack;
		*stack = (*stack)->next;
		free(itr);
	}
}
