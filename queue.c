#include "monty.h"


void _queue(stack_t **stack, unsigned int line_number);


/**
 * _queue - stack to a queue.
 * @stack: stack pointer.
 * @line_number: line number.
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
