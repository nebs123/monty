#include "monty.h"

/**
 * add_op - function for add opcode
 * @stack: pointer to a pointer to the stack
 * @line_number: line number for opcode
 *
 * Return: void (no return)
 */
void add_op(stack_t **stack, unsigned int line_number)
{
	stack_t *last = pop(stack), *pen = pop(stack);

	if (!last || !pen)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	push(stack, last->n + pen->n);
	free(last);
	free(pen);
}

/**
 * nop_op - function for nop opcode
 * @stack: pointer to a pointer to the stack
 * @line_number: line number for opcode
 *
 * Return: void (no return)
 */
void nop_op(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * sub_op - function for sub opcode
 * @stack: pointer to a pointer to the stack
 * @line_number: line number for opcode
 *
 * Return: void (no return)
 */
void sub_op(stack_t **stack, unsigned int line_number)
{
	stack_t *last = pop(stack), *pen = pop(stack);

	if (!last || !pen)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	push(stack, pen->n - last->n);
	free(last);
	free(pen);
}

/**
 * div_op - function for sub opcode
 * @stack: pointer to a pointer to the stack
 * @line_number: line number for opcode
 *
 * Return: void (no return)
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *last = pop(stack), *pen = pop(stack);

	if (!last || !pen)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (!last->n)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	push(stack, pen->n / last->n);
	free(last);
	free(pen);
}

/**
 * mul_op - function for mul opcode
 * @stack: pointer to a pointer to the stack
 * @line_number: line number for opcode
 *
 * Return: void (no return)
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	stack_t *last = pop(stack), *pen = pop(stack);

	if (!last || !pen)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	push(stack, pen->n * last->n);
	free(last);
	free(pen);
}
