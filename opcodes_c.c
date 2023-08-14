#include "monty.h"

/**
 * mod_monty - mods top 2 nodes of stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void mod_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpNode;
	char *errMsg1 = ": can't mod, stack too short\n";
	char *errMsg2 = ": division by zero\n";

	if (!(*stack))
		free_stack(stack, errMsg1);
	if (!((*stack)->next))
		free_stack(stack, errMsg1);
	if ((*stack)->n == 0)
		free_stack(stack, errMsg2);
	tmpNode = (*stack);
	tmpNode->next->n %= tmpNode->n;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmpNode);
	(void) line_number;
}

/**
 * pchar_monty - prints ASCII char of top node
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void pchar_monty(stack_t **stack, unsigned int line_number)
{
	char pchar;
	char *errMsg1 = ": can't pchar, stack empty\n";
	char *errMsg2 = ": can't pchar, value out of range\n";

	if (!(*stack))
		free_stack(stack, errMsg1);
	if ((*stack)->n < 0 || (*stack)->n > 127)
		free_stack(stack, errMsg2);
	pchar = (*stack)->n;
	printf("%c\n", pchar);
	(void) line_number;
}

/**
 * pstr_monty - prints nodes as str
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void pstr_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpNode;

	tmpNode = (*stack);
	while (tmpNode && tmpNode->n > 0 && tmpNode->n < 128)
	{
		printf("%c", tmpNode->n);
		tmpNode = tmpNode->next;
	}
	printf("\n");
	(void) line_number;
}

/**
 * rotl_monty - PLACEHOLDER
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void rotl_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpNode, *topNode, *botNode;

	if (!(*stack))
		return;
	if (!((*stack)->next))
		return;
	botNode = (*stack);
	topNode = (*stack)->next;
	tmpNode = (*stack);
	while (tmpNode->next)
		tmpNode = tmpNode->next;
	tmpNode->next = botNode;
	topNode->prev = NULL;
	(*stack) = topNode;
	botNode->prev = tmpNode;
	botNode->next = NULL;
	(void) line_number;
}

/**
 * rotr_monty - PLACEHOLDER
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void rotr_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpNode, *topNode, *botNode;

	if (!(*stack))
		return;
	if (!((*stack)->next))
		return;
	topNode = (*stack);
	while (topNode->next)
		topNode = topNode->next;
	botNode = topNode->prev;
	tmpNode = (*stack);
	tmpNode->prev = topNode;
	(*stack) = topNode;
	topNode->next = tmpNode;
	topNode->prev = NULL;
	botNode->next = NULL;
	(void) line_number;
}
