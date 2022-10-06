#include "monty.h"
/**
 * pop - pops and returns the last inserted element of stack
 * @stack: pointer to a pointer to the stack
 *
 * Return: last element to be inserted into stack
 */
stack_t *pop(stack_t **stack)
{
	stack_t *ret;

	if (!*stack)
		return (NULL);

	ret = *stack;
	*stack = (*stack)->next;
	ret->next = NULL;

	if (*stack)
		(*stack)->prev = NULL;
	return (ret);
}

/**
 * push - creates a new stack element and inserts it on top of the stack
 * @stack: pointer to a pointer to the stack
 * @val: value to assign to stack element
 * Return: pointer to the newly created stack
 */
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


/**
 * free_stack - frees the stack memory after program ends
 * @stack: pointer to the pointer to the stack
 *
 * Return: void (no return)
 */
void free_stack(stack_t **stack)
{
	stack_t *ptr = *stack;

	while (ptr)
	{
		if (ptr->next == NULL)
		{
			free(ptr);
			ptr = NULL;
		}
		else
		{
			ptr = ptr->next;
			free(ptr->prev);
		}
	}
}
