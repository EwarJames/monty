#include "monty.h"

/**
 *usage_error - Prints the usage error
 *Description: If user doesnt give file or more than valid arguments
 * Return: void
 **/
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 *open_error - Prints the can't open error
 *Description: print message if its not possible to open the file
 * @argv: arguments received by main, ni this case te filename
 * Return: no return.
 **/
void open_error(char **argv)
{
	char *filename = argv[1];

	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
/**
 * invalidInstruction_error -Prints Invalid instruction error.
 *Description: print message the file has an invalid instruction
 * @invInstruction: instruction
 * @line: line
 * Return: no return.
 **/
void invalidInstruction_error(char *invInstruction, unsigned int line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line, invInstruction);
	exit(EXIT_FAILURE);
}
/**
 * not_int_err - Prints not integer error
 *Description: print message if parameter received is not integer
 * @line: line
 * Return: No return.
 **/
void not_int_err(unsigned int line)
{
	fprintf(stderr, "L%u: usage: push integer\n", line);
	exit(EXIT_FAILURE);
}
/**
 * malloc_error - Prints malloc error
 *Description: print message if cant malloc anymore
 * Return: No return.
 **/
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
