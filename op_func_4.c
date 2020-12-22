#include "monty.h"

/**
 * func_pstr - prints the string starting at the stack of the stack.
 * @stack: element at the top of the stack (head)
 * @line_number: line
 * Return: void
 */
void func_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int ascii_num;

	(void)line_number;
	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		ascii_num = tmp->n;

		if (ascii_num <= 0 || ascii_num > 127)
			break;
		putchar(ascii_num);
		tmp = tmp->next;
	}
	putchar('\n');
}
