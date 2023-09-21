
#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void free_tokens(void);
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int get_type(stack_t *stack);

int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int starting(FILE *file_script);

/**
 * main - the entry point
 * @argc:  arguments
 * @argv:  arguments
 * Return: (EXIT_SUCCESS) or (EXIT_FAILURE)
 */
int main(int argc, char **argv)
{
	FILE *file_script = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_failure());
	file_script = fopen(argv[1], "r");
	if (file_script == NULL)
		return (open_failure(argv[1]));
	exit_code = starting(file_script);
	fclose(file_script);
	return (exit_code);
}

/**
 * starting - start all scripts.
 * @file_script: file script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int starting(FILE *file_script)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);
    int len = 0;


	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (fgets(line, len, file_script))
	{
		line_number++;
		op_Code = strtow(line, DELIMS);
		if (op_Code == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_failure());
		}
		else if (op_Code[0][0] == '#')
		{
			free_tokens();
			continue;
		}
		op_func = get_op_func(op_Code[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_failure(op_Code[0], line_number);
			free_tokens();
			break;
		}
		prev_tok_len = code_length();
		op_func(&stack, line_number);
		if (code_length() != prev_tok_len)
		{
			if (op_Code && op_Code[prev_tok_len])
				exit_status = atoi(op_Code[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_failure());
	}

	free(line);
	return (exit_status);
}

/**
 * free_tokens - free tokens.
 */
void free_tokens(void)
{
	size_t i = 0;

	if (op_Code == NULL)
		return;

	for (i = 0; op_Code[i]; i++)
		free(op_Code[i]);

	free(op_Code);
}



/**
 * is_empty_line - check line has delimiter.
 * @line: line pointer.
 * @delims: delimiter.
 *
 * Return:  - 1 or 0.
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - check an opcode.
 * @opcode: opcode.
 * Return: pointer.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", _push},
		{"pall", _pall},
        {"pint", _pint},
        {"pop", _pop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}
	return (NULL);
}

