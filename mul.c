
#include "monty.h"

void _mul(stack_t **stack, unsigned int line_number);

/**
 * _mul - multiplies values
 * @stack: stack pointer.
 * @line_number: line number.
 * Description: multiplie values.
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_failure(stack_failure(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	_pop(stack, line_number);
}
