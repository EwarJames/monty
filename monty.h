#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define DELIMS "\n \t\r"

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
 * struct instruction_s - opcoode and its function
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

/**
 * struct gen_s - globally defined variables, all rolled into one
 * @top: pointer to top of stack
 **/

typedef struct gen_s
{
  stack_t **top;

} gen_t;

extern gen_t gen;


void stack_init(stack_t **head);
void free_all(void);
int run_file(char *filename, stack_t **stack);
void func_call(stack_t **stack, char *op, unsigned int line_number);
void func_push(stack_t **stack, unsigned int line_number);
void func_pop(stack_t **stack, unsigned int line_number);
void func_pint(stack_t **stack, unsigned int line_number);
void func_pall(stack_t **stack, unsigned int line_number);
void func_swap(stack_t **stack, unsigned int line_number);
void func_add(stack_t **stack, unsigned int line_number);
void func_nop(stack_t **stack, unsigned int line_number);
void func_sub(stack_t **stack, unsigned int line_number);
void func_div(stack_t **stack, unsigned int line_number);
void func_mul(stack_t **stack, unsigned int line_number);
void func_mod(stack_t **stack, unsigned int line_number);
void func_pchar(stack_t **stack, unsigned int line_number);
void func_pstr(stack_t **stack, unsigned int line_number);
void func_rotl(stack_t **stack, unsigned int line_number);
void func_rotr(stack_t **stack, unsigned int line_number);
int is_leading_digit(char ascii_char);
int errors_check(char *num_string, unsigned int line_number);

#endif
