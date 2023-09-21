
#include "monty.h"


void _pchar(stack_t **stack, unsigned int line_number);
int pchar_failure(unsigned int line_number, char *message);

/**
 * _pchar - character of last in stack
 * @stack: stack pointer.
 * @line_number: ine number.
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

/**
 * pchar_failure - pchar error messages
 * @line_number: line number.
 * @message: error message.
 * Return: (EXIT_FAILURE).
 */
int pchar_failure(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}

