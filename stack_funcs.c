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

/**
 * enqueue - creates a new element and inserts it at bottom of the stack/queue
 * @stack: pointer to a pointer to the stack/queue
 * @val: value to assign to stack/queue element
 * Return: pointer to the newly created element
 */
stack_t *enqueue(stack_t **stack, int val)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *prev = NULL, *ptr = *stack;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while (ptr)
	{
		prev = ptr;
		ptr = ptr->next;
	}

	new_node->n = val;
	new_node->next = NULL;
	new_node->prev = prev;

	if (prev)
	{
		prev->next = new_node;
	} else
	{
		*stack = new_node;
	}

	return (new_node);
}

/**
 * pop_end - pops the last element of stack
 * @stack: pointer to a pointer to the stack/queue
 * Return: pointer to the newly created element or null on failure
 */
stack_t *pop_end(stack_t **stack)
{
	stack_t *prev = NULL, *ptr = *stack;

	while (ptr)
	{
		prev = ptr;
		ptr = ptr->next;
	}

	if (prev)
	{
		if (prev->prev)
			prev->prev->next = NULL;
		else
			*stack = NULL;
		prev->prev = NULL;
	}

	return (prev);
}
