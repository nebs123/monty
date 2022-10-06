#include "monty.h"

/**
 * main - main loop of the monty bytecode interpreter
 * @argc: number of command line args
 * @argv: command line args
 * Return: 0 on success, otherwise exits with failure code
 */

int main(int argc, char *argv[])
{
	size_t nb;
	unsigned int len;
	ssize_t read;
	char *buf = NULL, *opcode = NULL;
	stack_t *stack = NULL;
	FILE *file;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (len = 1; (read = getline(&buf, &nb, file)) != -1; len++)
	{
		if (buf[read - 1] == '\n')
			buf[read - 1] = '\0';
		opcode =  strtok(buf, " ");
		printf("opcode: %s\n", opcode);
		call_opcode(opcode, &stack, len);
	}
	free(buf);
	return (0);
}

void call_opcode(char *opcode, stack_t **stack, unsigned int line)
{
	instruction_t instructions[] = {
		{"push", push_op},
	};
	unsigned int i;

	for (i = 0; i < 1; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			break;
	}
	if (i < 1)
		(*instructions[i].f)(stack, line);
	else
		fprintf(stderr, "L%u: unknown instruction %s\n", line, opcode);
}