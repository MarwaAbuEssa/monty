
#include "monty.h"

void free_opcode(void);
unsigned int opcode_length(void);
int check_line(char *line, char *delims);
void (*opcode_fn(char *opcode))(stack_t**, unsigned int);
int start(FILE *file_script);

char **op_Code = NULL;
/**
 * main - the entry point
 * @argc:  arguments
 * @argv:  arguments
 * Return: SUCCESS or FAILURE
 */

int main(int argc, char **argv)
{
	FILE *file_script = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
	{
		return (usage_failure());
	}
	file_script = fopen(argv[1], "r");
	if (file_script == NULL)
	{
		return (file_failure(argv[1]));
	}
	exit_code = start(file_script);
	fclose(file_script);
	return (exit_code);
}

/**
 * free_opcode - frees  op_Code.
 */
void free_opcode(void)
{
	size_t i = 0;

	if (op_Code == NULL)
		return;

	for (i = 0; op_Code[i]; i++)
		free(op_Code[i]);

	free(op_Code);
}

/**
 * opcode_length - Gets the length of current op_Code.
 *
 * Return: Length of current op_Code (as int).
 */
unsigned int opcode_length(void)
{
	unsigned int toks_len = 0;

	while (op_Code[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * check_line - get line .
 * @line: liune pointer
 * @delims: delimiter.
 * Return:  1./ 0.
 */
int check_line(char *line, char *delims)
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
 * opcode_fn - opcode for function.
 * @opcode: opcode .
 * Return: function pointer .
 */
void (*opcode_fn(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
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

/**
 * start - start monty.
 * @file_script: file script.
 * Return: success or failed.
 */
int start(FILE *file_script)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (create(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, file_script) > 0)
	{
		line_number++;
		op_Code = strtow(line, DELIMS);
		if (op_Code == NULL)
		{
			if (check_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_failure());
		}
		else if (op_Code[0][0] == '#')
		{
			free_opcode();
			continue;
		}
		op_func = opcode_fn(op_Code[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_failure(op_Code[0], line_number);
			free_opcode();
			break;
		}
		prev_tok_len = opcode_length();
		op_func(&stack, line_number);
		if (opcode_length() != prev_tok_len)
		{
			if (op_Code && op_Code[prev_tok_len])
				exit_status = atoi(op_Code[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_opcode();
			break;
		}
		free_opcode();
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

