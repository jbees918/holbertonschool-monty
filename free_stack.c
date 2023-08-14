#include "monty.h"

/**
 * free_stack - free DLL type stack
 * @stack: DLL type stack head
 * @messg: associated exit message
 * Return: void
 */
void free_stack(stack_t **stack, char *messg)
{
	stack_t *scrubber;

	if (messg)
	{
		if (messg[0] == '!')
		{
			messg++;
			fprintf(stderr, "L%d%s%s\n", daedalus.op_line, messg, daedalus.op_code);
		}
		else
			fprintf(stderr, "L%d%s", daedalus.op_line, messg);
	}
	if (daedalus.line_ref)
		free(daedalus.line_ref);
	fclose(daedalus.file_ref);
	if (*stack)
	{
		while (*stack)
		{
			scrubber = (*stack)->next;
			free(*stack);
			(*stack) = scrubber;
		}
	}
	if (messg)
		exit(EXIT_FAILURE);
	else
		return;
}
