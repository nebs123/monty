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

/**
 * pchar_op - function for pchar opcode
 * @stack: pointer to a pointer to the stack
 * @line_number: line number for opcode
 *
 * Return: void (no return)
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (head)
	{
		if (head->n >= 0 && head->n <= 127)
			printf("%c\n", head->n);
		else
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n"
				, line_number);
			exit(EXIT_FAILURE);
		}
	} else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr_op - function for pstr opcode
 * @stack: pointer to a pointer to the stack
 * @line_number: line number for opcode
 *
 * Return: void (no return)
 */
void pstr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	(void) line_number;
	while (head)
	{
		if (head->n <= 0  || head->n > 127)
			break;
		printf("%c", head->n);
		head = head->next;
	}
	printf("\n");
}

/**
 * rotl_op - function for rotl opcode
 * @stack: pointer to a pointer to the stack
 * @line_number: line number for opcode
 *
 * Return: void (no return)
 */
void rotl_op(stack_t **stack, unsigned int line_number)
{
	stack_t *head = pop(stack), *ret;

	(void) line_number;
	if (head)
	{
		ret = enqueue(stack, head->n);
		free(head);
		if (!ret)
			fprintf(stderr, "Something has gone wrong in enqueue\n");
	}
}

/**
 * rotr_op - function for rotr opcode
 * @stack: pointer to a pointer to the stack
 * @line_number: line number for opcode
 *
 * Return: void (no return)
 */
void rotr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = pop_end(stack), *ret;

	(void) line_number;
	if (tail)
	{
		ret = push(stack, tail->n);
		free(tail);
		if (!ret)
			fprintf(stderr, "Something has gone wrong in push\n");
	}
}
