#include "monty.h"

/**
* func_call - Decides function to call based on the tokens.
* @stack: double pointer to head of stack data structure
* @op: operator, aka token[0] from getline
* @line_number: line in byte-code file being processed, zero indexed
* Return: int for mysterious purposes
**/
void func_call(stack_t **stack, char *op, unsigned int line_number)
{
	int i = 0;
	instruction_t all_ops[] = {
		{"push", func_push},
		{"pall", func_pall},
		{"pint", func_pint},
		{"pop", func_pop},
		{"swap", func_swap},
		{"add", func_add},
		{"nop", func_nop},
		{"sub", func_sub},
		{"div", func_div},
		{"mul", func_mul},
		{"mod", func_mod},
		{"pchar", func_pchar},
		{"pstr", func_pstr},
		{"rotl", func_rotl},
		{"rotr", func_rotr},
		{NULL, NULL}
	};

	for (i = 0; all_ops[i].opcode; i++)
	{
		if (strcmp(op, all_ops[i].opcode) == 0)
		{
			all_ops[i].f(stack, line_number);
			return;
		}
	}
	if (strlen(op) != 0 && op[0] != '#')
	{
		printf("L%u: unknown func %s\n", line_number, op);
		exit(EXIT_FAILURE);
	}
}
