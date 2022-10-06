#include "monty.h"

/**
 * queue_op - function for queue opcode
 * @stack: pointer to a pointer to the stack
 * @line_number: line number for opcode
 *
 * Return: void (no return)
 */
void queue_op(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	stack_queue = 0;
}

/**
 * stack_op - function for stack opcode
 * @stack: pointer to a pointer to the stack
 * @line_number: line number for opcode
 *
 * Return: void (no return)
 */
void stack_op(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	stack_queue = 1;
}
