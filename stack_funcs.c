#include "monty.h"

stack_t *pop(stack_t **stack)
{
	stack_t *returnable;

	if (!*stack)
		return NULL;
	returnable = *stack;
	*stack = (*stack)->next;
	returnable->next = NULL;

	if (*stack)
		(*stack)->prev = NULL;
	return (returnable);
}

stack_t *push(stack_t **stack, int val)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = val;
	new_node->prev = NULL;

	if (*stack)
		(*stack)->prev = new_node;
	new_node->next = *stack;
	*stack = new_node;

	return (new_node);
}
