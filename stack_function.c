#include "monty.h"

void _stack(stack_t **stack, unsigned int line_number);

/**
 * _stack -  queue to a stack.
 * @stack: stack pointer.
 * @line_number: line number.
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}
