#include "monty.h"

void _pint(stack_t **stack, unsigned int line_number);
int pint_failure(unsigned int line_number);
/**
 * _pint - print stack.
 * @stack: stack pointer.
 * @line_number: line number.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_failure(pint_failure(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}

/**
 * pint_failure - pint error messagess.
 * @line_number: line number.
 * Return: (EXIT_FAILURE).
 */
int pint_failure(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}


