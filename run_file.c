#include "monty.h"

gen_t gen;

/**
 * run_file - run the whole monty file
 * @filename: str name of monty opcode file
 * @stack: double pointer to top of stack data struct
 * Return: return an error code or success
 **/
int run_file(char *filename, stack_t **stack)
{
	size_t len;
	ssize_t read;
	unsigned int line_number = 0;
	char *line = NULL;
	FILE *fp;
	char *op;


	if (!filename)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	atexit(free_all);
	while ((read = getline(&line, &len, fp)) != -1)
	{
		op = strtok(line, DELIMS);
		line_number++;
		if (op)
			func_call(stack, op, line_number);
	}
	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}

/**
 * stack_init - initialize all the things
 * @head: top of stack data structure
 **/
void stack_init(stack_t **head)
{
	*head = NULL;

	gen.top = head;
}

/**
 * free_all - free all malloc'ed memory
 **/

void free_all(void)
{
	stack_t *tmp1, *tmp2 = NULL;

	tmp1 = *(gen.top);
	while (tmp1 != NULL)
	{
		tmp1 = tmp2->next;
		free(tmp1);
		tmp1 = tmp2;
	}
}
