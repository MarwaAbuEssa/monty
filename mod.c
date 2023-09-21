
#include "monty.h"

void _mod(stack_t **stack, unsigned int line_number);

/**
 * _mod - modulus values.
 * @stack: stack pointer.
 * @line_number: line number.
 * Description: modulues result.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_failure(stack_failure(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_failure(div_failure(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	_pop(stack, line_number);
}
