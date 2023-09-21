
#include "monty.h"

void _add(stack_t **stack, unsigned int line_number);

/**
 * _add - sum values.
 * @stack: Astack pointer.
 * @line_number: line number.
 * Description: store node value
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_failure(stack_failure(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	_pop(stack, line_number);
}

