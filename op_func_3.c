#include "monty.h"

/**
 *func_mod - print the mode.
 *
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: no return.
 **/
void func_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next ==  NULL)
		mod_error(line_number);

	if ((*stack)->n == 0)
		div_error2(line_number);

	tmp = (*stack)->next;
	tmp->n = (tmp->n) % (*stack)->n;
	func_pop(stack, line_number);
}
/**
 * func_rotl - Implement the rotl opcode.
 * 
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: no return.
 **/
void func_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack, *tmp, *new_last;

	(void)line_number;

	if (*stack == NULL || (*stack != NULL && (*stack)->next == NULL))
		return;

	new_last = *stack;
	tmp = *stack;

	while (tmp->next)
		tmp = tmp->next;

	new_stack = (*stack)->next;
	new_last->next = NULL;
	new_last->prev = tmp;
	tmp->next = new_last;
	new_stack->prev = NULL;
	*stack = new_stack;
}
/**
 * func_rotr - Implement the rotr opcode.
 * 
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: no return.
 **/
void func_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (*stack == NULL || (*stack != NULL && (*stack)->next == NULL))
		return;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}
/**
 * func_nop - Implement the nop opcode
 * 
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: no return.
 **/
void func_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * func_pchar - Prints the char at the stack of the stack.
 * 
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: no return.
 **/
void func_pchar(stack_t **stack, unsigned int line_number)
{
	int ascii_num;

	if (*stack == NULL)
		pchar_error2(line_number);

	ascii_num = (*stack)->n;

	if (ascii_num < 0 || ascii_num > 127)
		pchar_error(line_number);
	putchar(ascii_num);
	putchar('\n');
}
