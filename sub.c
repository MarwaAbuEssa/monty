
#include "monty.h"


void _sub(stack_t **stack, unsigned int line_number);
/**
 * _sub - subtract values
 * @stack: stack pointer.
 * @line_number: line number.
 * Description: result of subtract.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_failure(stack_failure(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	_pop(stack, line_number);
}
