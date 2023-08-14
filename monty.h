#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of stack or queue
 * @n: integer
 * @prev: points to previous element of the stack or queue
 * @next: points to next element of the stack or queue
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
 * struct instruction_s - opcode and function
 * @opcode: the opcode
 * @f: function to handle opcode
 *
 * Description: opcode and function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * glob_s - global struct
 * @fd: file descriptor
 * @line: line to perform getline on
 *
 * Description:
 */
typedef struct global_s
{
	FILE *fd;
	char *line;
} global_t;

extern int value;
extern global_t global;

stack_t *add_node(int n);
void monty_read(char *argv);
int monty_call(stack_t **stack, char *arg, char *item, int count);
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void free_monty(stack_t *stack);
void freestack(stack_t **stack);
void push_error(FILE *fd, char *line, stack_t *stack, int count);
void ins_error(FILE *fd, char *line, stack_t *stack, char *count, int item);
int _strlen(char *s);
int int_check(char *c);

#endif
