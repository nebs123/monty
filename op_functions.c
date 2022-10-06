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
