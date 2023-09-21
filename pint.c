#include "monty.h"

void _pint(stack_t **stack, unsigned int line_number);

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


