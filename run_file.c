#include "monty.h"

/**
 * get_op_code - contain the function that will perform the operation
 * @token: operation code
 * @line: line readed
 * Return: void
 */
void (*get_op_code(char *token, unsigned int line)) (stack_t **, unsigned int)
{
	int i;
	instruction_t operation[] = {
		{"push", func_push},
		{"pall", func_pall},
		{"pint", func_pint},
		{"pop", func_pop},
		{"swap", func_swap},
		{"nop", func_nop},
		{"add", func_add},
		{"sub", func_sub},
		{"div", func_div},
		{"mul", func_mul},
		{"mod", func_mod},
		{"rotl", func_rotl},
		{"rotr", func_rotr},
		{"pchar", func_pchar},
		{"pstr", func_pstr},
		{NULL, NULL}
	};
	for (i = 0; operation[i].opcode != NULL; i++)
	{
		if (strcmp(token, operation[i].opcode) == 0)
		{
			return (operation[i].f);
		}
	}
	invalidInstruction_error(token, line);
	return (NULL);
}
