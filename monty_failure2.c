
#include "monty.h"

int pint_failure(unsigned int line_number);

/**
 * pint_failure - failure message.
 * @line_number: line number.
 * Return: (EXIT_FAILURE).
 */
int pint_failure(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}