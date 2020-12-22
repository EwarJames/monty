#include "monty.h"

/**
 *func_swap - swaps the stack 2 elements of stack.
 *
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: no return.
 **/

void func_swap(stack_t **stack, unsigned int line_number)
{
	int num;

	if (*stack == NULL || (*stack)->next == NULL)
		swap_error(line_number);

	num = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = num;
}

/**
 *func_add - adds the stack two elements of the stack.
 *
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: no return
 **/

void func_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		add_error(line_number);

	tmp = (*stack)->next;
	tmp->n += (*stack)->n;
	func_pop(stack, line_number);
}
/**
 *func_sub - Sub the stack element of stck.
 *
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: no return.
 **/
void func_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		sub_error(line_number);

	tmp = (*stack)->next;
	tmp->n -= (*stack)->n;
	func_pop(stack, line_number);
}
/**
 * func_div - main entry
 * Description: Divides the seccond stack
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: no return.
 */

void func_div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		div_error(line_number);

	if ((*stack)->n == 0)
		div_error2(line_number);

	tmp = (*stack)->next;
	tmp->n = (tmp->n) / (*stack)->n;
	func_pop(stack, line_number);
}
/**
 * func_mul - multiplies the seccond stack element of stack and the top element
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 */
void func_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		mul_error(line_number);

	tmp = (*stack)->next;
	tmp->n *= (*stack)->n;
	func_pop(stack, line_number);
}
