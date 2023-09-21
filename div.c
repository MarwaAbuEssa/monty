
#include "monty.h"

void _div(stack_t **stack, unsigned int line_number);
int div_failure(unsigned int line_number);

/**
 * _div - divide values
 * @stack: stack pointer.
 * @line_number: line number.
 * Description: division result
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_failure(stack_failure(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_failure(div_failure(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	_pop(stack, line_number);
}


/**
 * div_failure - division error message.
 * @line_number: line number.
 * Return: (EXIT_FAILURE).
 */
int div_failure(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}