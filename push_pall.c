#include "monty.h"

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);

/**
 * _push - pushes  value to a stack.
 * @stack: pointer  stack.
 * @line_number: line number.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_failure(malloc_failure());
		return;
	}

	if (op_Code[1] == NULL)
	{
		set_failure(int_failure(line_number));
		return;
	}

	for (i = 0; op_Code[1][i]; i++)
	{
		if (op_Code[1][i] == '-' && i == 0)
			continue;
		if (op_Code[1][i] < '0' || op_Code[1][i] > '9')
		{
			set_failure(int_failure(line_number));
			return;
		}
	}
	new->n = atoi(op_Code[1]);

	if (stack_Type(*stack) == STACK)
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * _pall - prints the values of a stack.
 * @stack: pointer a stack.
 * @line_number:  line number.
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}
