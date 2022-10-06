#include "monty.h"

/**
 * push_op - function for push opcode
 * @stack: pointer to a pointer to the stack
 * @line_number: line number for opcode
 *
 * Return: void (no return)
 */
void push_op(stack_t **stack, unsigned int line_number)
{
	char *end, *param;
	stack_t *ret;

	param = strtok(NULL, " ");
	if (param == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	strtol(param, &end, 10);
	if (end == param || *end != '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	ret = push(stack, atoi(param));
	if (!ret)
		fprintf(stderr, "Something went wrong in push");
}

/**
 * pall_op - function for pall opcode
 * @stack: pointer to a pointer to the stack
 * @line_number: line number for opcode
 *
 * Return: void (no return)
 */
void pall_op(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	(void) line_number;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pint_op - function for pint opcode
 * @stack: pointer to a pointer to the stack
 * @line_number: line number for opcode
 *
 * Return: void (no return)
 */
void pint_op(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	if (head)
	{
		printf("%d\n", head->n);
	} else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop_op - function for pop opcode
 * @stack: pointer to a pointer to the stack
 * @line_number: line number for opcode
 *
 * Return: void (no return)
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *popped = pop(stack);

	if (!popped)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	free(popped);
}

/**
 * swap_op - function for swap opcode
 * @stack: pointer to a pointer to the stack
 * @line_number: line number for opcode
 *
 * Return: void (no return)
 */
void swap_op(stack_t **stack, unsigned int line_number)
{
	stack_t *last = pop(stack), *pen = pop(stack);

	if (!last || !pen)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	push(stack, last->n);
	free(last);
	push(stack, pen->n);
	free(pen);
}
