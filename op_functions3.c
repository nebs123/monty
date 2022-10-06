#include "monty.h"

/**
 * mod_op - function for mod opcode
 * @stack: pointer to a pointer to the stack
 * @line_number: line number for opcode
 *
 * Return: void (no return)
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
	stack_t *last = pop(stack), *pen = pop(stack);

	if (!last || !pen)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (!last->n)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	push(stack, pen->n % last->n);
	free(last);
	free(pen);
}
