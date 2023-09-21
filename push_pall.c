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
	stack_t *tmp, *pointer;
	int i;

	pointer = malloc(sizeof(stack_t));
	if (pointer == NULL)
	{
		set_error(malloc_failure());
		return;
	}

	if (op_Code[1] == NULL)
	{
		set_error(int_failure(line_number));
		return;
	}

	for (i = 0; op_Code[1][i]; i++)
	{
		if (op_Code[1][i] == '-' && i == 0)
				continue;
		if (op_Code[1][i] < '0' || op_Code[1][i] > '9')
		{
				set_error(int_failure(line_number));
					return;
		}
	}
	pointer->n = atoi(op_Code[1]);

	if (get_type(*stack) == STACK) 
	{
		tmp = (*stack)->next;
		pointer->prev = *stack;
		pointer->next = tmp;
		if (tmp)
				tmp->prev = pointer;
		(*stack)->next = pointer;
	}
	else 
	{
		tmp = *stack;
		while (tmp->next)
				tmp = tmp->next;
		pointer->prev = tmp;
		pointer->next = NULL;
		tmp->next = pointer;
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


