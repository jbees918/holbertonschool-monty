#include "monty.h"

/**
 * op_fun_res - matches inbound opcode to supported
 * @stack: pointer to stack HEAD
 * Return: void
 */
void op_fun_res(stack_t **stack)
{
	unsigned int i;
	char *errMsg1 = "!: unknown instruction ";
	instruction_t betty[] = {
		{"pall", pall_monty},
		{"push", push_monty},
		{"pint", pint_monty},
		{"nop", nop_monty},
		{"pop", pop_monty},
		{"swap", swap_monty},
		{"add", add_monty},
		{"sub", sub_monty},
		{"div", div_monty},
		{"mul", mul_monty},
		{"mod", mod_monty},
		{"pchar", pchar_monty},
		{"pstr", pstr_monty},
		{"rotl", rotl_monty},
		{"rotr", rotr_monty},
		{NULL, NULL}
	};

	for (i = 0; betty[i].opcode; i++)
	{
		if (strcmp(betty[i].opcode, daedalus.op_code) == 0)
		{
			betty[i].f(stack, daedalus.op_line);
			return;
		}
	}
	free_stack(stack, errMsg1);
}
