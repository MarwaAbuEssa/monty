#include "monty.h"


void _pop(stack_t **stack, unsigned int line_number);
int pop_failure(unsigned int line_number);

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
		set_failure(pop_failure(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}


/**
 * pop_failure - pop error messages.
 * @line_number: line number.
 *
 * Return: (EXIT_FAILURE).
 */
int pop_failure(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}