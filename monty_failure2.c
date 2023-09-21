
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

/**
 * pop_failure - print pop failure.
 * @line_number: Line number.
 *
 * Return: (EXIT_FAILURE).
 */
int pop_failure(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}