#include "monty.h"

/**
 * push_monty - pushes int to DLL stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void push_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;
	unsigned int j = 1;
	int n;
	char *errMsg1 = ": usage: push integer\n";

	if (!(daedalus.op_arg))
		free_stack(stack, errMsg1);
	if (!((daedalus.op_arg[0] >= '0' && daedalus.op_arg[0] <= '9')
	|| daedalus.op_arg[0] == '-'))
		free_stack(stack, errMsg1);
	while (daedalus.op_arg[j])
	{
		if (isdigit(daedalus.op_arg[j]) == 0)
			free_stack(stack, errMsg1);
		j++;
	}
	newNode = malloc(sizeof(stack_t));
	n = atoi(daedalus.op_arg);
	newNode->n = n;
	newNode->prev = NULL;
	newNode->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = newNode;
	*stack = newNode;
	(void) line_number;
}

/**
 * pall_monty - prints DLL type stack to SO
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void pall_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *nodePtr;

	nodePtr = (*stack);
	while (nodePtr)
	{
		printf("%d\n", nodePtr->n);
		nodePtr = nodePtr->next;
	}
	(void) line_number;
}

/**
 * pint_monty - prints top int of stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void pint_monty(stack_t **stack, unsigned int line_number)
{
	char *errMsg1 = ": can't pint, stack empty\n";

	if ((*stack) == NULL)
		free_stack(stack, errMsg1);
	else
	{
		printf("%d\n", (*stack)->n);
	}
	(void) line_number;
}

/**
 * nop_monty - does nothing to stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void nop_monty(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * pop_monty - removes top int node of stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void pop_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *nodeHold;
	char *errMsg1 = ": can't pop an empty stack\n";

	if (!(*stack))
		free_stack(stack, errMsg1);
	else
	{
		nodeHold = (*stack)->next;
		free((*stack));
		(*stack) = nodeHold;
	}
	(void) line_number;
}
