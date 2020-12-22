#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern int n, number;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void usage_error(void);
void open_error(char **);
void invalidInstruction_error(char *invInstruction, unsigned int line);
void not_int_err(unsigned int line);
void malloc_error(void);
void pint_error(unsigned int line);
void pop_error(unsigned int line);
void swap_error(unsigned int line);
void add_error(unsigned int line);
void sub_error(unsigned int line);
void div_error(unsigned int line);
void div_error2(unsigned int line);
void mul_error(unsigned int line);
void mod_error(unsigned int line);
void pchar_error(unsigned int line);
void pchar_error2(unsigned int line);
void open_and_read(char **argv);
int is_number(char *token);
int is_comment(char *token, int line_counter);
void (*get_op_code(char *token, unsigned int line)) (stack_t **, unsigned int);
void func_push(stack_t **stack, unsigned int line_number);
void func_pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void func_pint(stack_t **stack, unsigned int line_number);
void func_pop(stack_t **stack, unsigned int line_number);
void func_swap(stack_t **stack, unsigned int line);
void func_add(stack_t **stack, unsigned int line);
void func_sub(stack_t **stack, unsigned int line_number);
void func_div(stack_t **stack, unsigned int line_number);
void func_mul(stack_t **stack, unsigned int line);
void func_mod(stack_t **stack, unsigned int line_number);
void func_rotl(stack_t **stack, unsigned int line_number);
void func_rotr(stack_t **stack, unsigned int line_number);
void func_nop(stack_t **stack, unsigned int line);
void func_pchar(stack_t **stack, unsigned int line_number);
void func_pstr(stack_t **stack, unsigned int line_number);

#endif
