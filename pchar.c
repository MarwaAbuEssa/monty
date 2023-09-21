
#include "monty.h"


void _pchar(stack_t **stack, unsigned int line_number);

/**
 * _pchar - Prints the character in the top value
 *               node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_failure(pchar_failure(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_failure(pchar_failure(line_number,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}


