#include "monty.h"
#include <string.h>

void _stack(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);
int create(stack_t **stack);
int stack_Type(stack_t *stack);
int stack_failure(unsigned int line_number, char *op);

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

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * create - create a  stack.
 * @stack: stack pointer.
 * Return: EXIT_FAILURE or EXIT_SUCCESS.
 */
int create(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_failure());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * stack_Type - get type of datasctructure.
 * @stack: stack or queue pointer.
 * Return:  (0) or (1) or 2.
 */
int stack_Type(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}

/**
 * stack_failure - stack failure error message.
 * @line_number: line number .
 * @op: operation .
 * Return: EXIT_FAILURE.
 */
int stack_failure(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}