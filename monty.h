#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void call_opcode(char *opcode, stack_t **stack, unsigned int line);
void push_op(stack_t **stack, unsigned int line_number);
void pall_op(stack_t **stack, unsigned int line_number);
void pint_op(stack_t **stack, unsigned int line_number);
void pop_op(stack_t **stack, unsigned int line_number);
void swap_op(stack_t **stack, unsigned int line_number);
void add_op(stack_t **stack, unsigned int line_number);
void nop_op(stack_t **stack, unsigned int line_number);
void sub_op(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mul_op(stack_t **stack, unsigned int line_number);
void mod_op(stack_t **stack, unsigned int line_number);
void pchar_op(stack_t **stack, unsigned int line_number);
void pstr_op(stack_t **stack, unsigned int line_number);
void rotl_op(stack_t **stack, unsigned int line_number);
void rotr_op(stack_t **stack, unsigned int line_number);
stack_t *pop(stack_t **stack);
stack_t *pop_end(stack_t **stack);
stack_t *push(stack_t **stack, int val);
stack_t *enqueue(stack_t **stack, int val);
void free_stack(stack_t **stack);
#endif
