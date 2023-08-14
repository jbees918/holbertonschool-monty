#include "monty.h"

struct global_s daedalus;

/**
 * main - Entry point for monty
 * @argc: arg count
 * @argv: array of input args
 * Return: Always 0 on completion, otherwise 1 on exit fail
 */
int main(int argc, char *argv[])
{
	stack_t *stack_prime = NULL;
	FILE *inbound_file = NULL;
	size_t n = 0;
	char *line_buff = NULL;
	const char delims[] = " \t\n";

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	inbound_file = fopen(argv[1], "r");
	if (!(inbound_file))
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	daedalus.file_ref = inbound_file;
	daedalus.op_line = 0;
	while (getline(&line_buff, &n, inbound_file) != -1)
	{
		daedalus.op_line++;
		daedalus.line_ref = line_buff;
		daedalus.op_code = strtok(line_buff, delims);
		if (!daedalus.op_code || daedalus.op_code[0] == '#')
			continue;
		daedalus.op_arg = strtok(NULL, delims);
		op_fun_res(&stack_prime);
	}
	free_stack(&stack_prime, NULL);
	return (0);
}
