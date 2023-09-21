#include "monty.h"

int usage_failure(void);
int malloc_failure(void);
int file_failure(char *filename);
int unknown_failure(char *opcode, unsigned int line_number);
int int_failure(unsigned int line_number);

/**
 * usage_failure - usage error message.
 * Return: EXIT_FAILURE.
 */
int usage_failure(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_failure - malloc error message.
 * Return: EXIT_FAILURE.
 */
int malloc_failure(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * file_failure - file error message.
 * @filename: file name
 * Return: EXIT_FAILURE.
 */
int file_failure(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_failure - unknown error message.
 * @opcode: Opcode of operation.
 * @line_number: line number.
 * Return: EXIT_FAILURE.
 */
int unknown_failure(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * int_failure - argument error message.
 * @line_number: line number.
 * Return: EXIT_FAILURE.
 */
int int_failure(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}



/**
 * set_failure - assign error code.
 * @code: op_Code.
 */
void set_failure(int code)
{
	int toks_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = opcode_length();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_Code)
	{
		malloc_failure();
		return;
	}
	while (i < toks_len)
	{
		new_toks[i] = op_Code[i];
		i++;
	}
	exit_str = get_int(code);
	if (!exit_str)
	{
		free(new_toks);
		malloc_failure();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(op_Code);
	op_Code = new_toks;
}
