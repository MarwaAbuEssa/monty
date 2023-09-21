#include "monty.h"

void _pop(stack_t **stack, unsigned int line_number);

/**
 * _pop - remove last element.
 * @stack: stack pointer.
 * @line_number: line number.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_error(pop_failure(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

