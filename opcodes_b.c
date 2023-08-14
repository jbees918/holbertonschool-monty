#include "monty.h"

/**
 * swap_monty - swaps top two nodes of stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void swap_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *nodeHold;
	char *errMsg1 = ": can't swap, stack too short\n";

	if (!(*stack))
		free_stack(stack, errMsg1);
	if (!(*stack)->next)
		free_stack(stack, errMsg1);
	nodeHold = (*stack)->next;
	(*stack)->next = nodeHold->next;
	(*stack)->prev = nodeHold;
	nodeHold->next = (*stack);
	nodeHold->prev = NULL;
	(*stack) = nodeHold;
	(void) line_number;
}

/**
 * add_monty - adds top 2 nodes of stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void add_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *nodeHold;
	char *errMsg1 = ": can't add, stack too short\n";

	if (!(*stack))
		free_stack(stack, errMsg1);
	if (!((*stack)->next))
		free_stack(stack, errMsg1);
	nodeHold = (*stack);
	nodeHold->next->n = (((*stack)->n) + ((*stack)->next->n));
	(*stack) = nodeHold->next;
	free(nodeHold);
	(void) line_number;
}

/**
 * sub_monty - subtracts top 2 nodes of stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void sub_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpNode;
	char *errMsg1 = ": can't sub, stack too short\n";

	if (!(*stack))
		free_stack(stack, errMsg1);
	if (!((*stack)->next))
		free_stack(stack, errMsg1);
	tmpNode = (*stack);
	tmpNode->next->n -= tmpNode->n;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmpNode);
	(void) line_number;
}

/**
 * div_monty - divides top 2 nodes of stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void div_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpNode;
	char *errMsg1 = ": can't div, stack too short\n";
	char *errMsg2 = ": division by zero\n";

	if (!(*stack))
		free_stack(stack, errMsg1);
	if (!((*stack)->next))
		free_stack(stack, errMsg1);
	if ((*stack)->n == 0)
		free_stack(stack, errMsg2);
	tmpNode = (*stack);
	tmpNode->next->n /= tmpNode->n;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmpNode);
	(void) line_number;
}

/**
 * mul_monty - multiplies top 2 nodes of stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void mul_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpNode;
	char *errMsg1 = ":can't mul, stack too short\n";

	if (!(*stack))
		free_stack(stack, errMsg1);
	if (!((*stack)->next))
		free_stack(stack, errMsg1);
	tmpNode = (*stack);
	tmpNode->next->n *= tmpNode->n;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmpNode);
	(void) line_number;
}
