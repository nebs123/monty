#include "monty.h"

void push_op(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
	printf("Inside push_op, input: %d\n", atoi(strtok(NULL, " ")));
}
