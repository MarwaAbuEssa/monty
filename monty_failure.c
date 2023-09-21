
#include "monty.h"

int usage_failure(void);
int malloc_failure(void);
int open_failure(char *filename);
int unknown_failure(char *opcode, unsigned int line_number);
int int_failure(unsigned int line_number);

/**
 * usage_failure - usage message.
 *
 * Return: EXIT_FAILURE.
 */
int usage_failure(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_failure - malloc message.
 *
 * Return: EXIT_FAILURE.
 */
int malloc_failure(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * open_failure - opening error message.
 * @filename: file name
 *
 * Return: EXIT_FAILURE.
 */
int open_failure(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_failure - unknowwn  message.
 * @opcode: Opcode
 * @line_number: line number.
 *
 * Return: EXIT_FAILURE
 */
int unknown_failure(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * int_failure - int messages.
 * @line_number: line number.
 *
 * Return: EXIT_FAILURE.
 */
int int_failure(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}

