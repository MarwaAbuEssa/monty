
#include "monty.h"

void _pstr(stack_t **stack, unsigned int line_number);

/**
 * _pstr - string in stacks.
 * @stack: stack pointer.
 * @line_number: line number.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
	(void)line_number;
}
