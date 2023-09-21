#include "monty.h"


unsigned int code_length(void);

/**
 * set_error - set error code
 *
 * Description: set error code.
 * @error_code: integer.
 */

void set_error(int error_code)
{
	int c_length = 0, i = 0;
	char *exit_str = NULL;
	char **new_code = NULL;

	c_length = code_length();
	new_code = malloc(sizeof(char *) * (c_length + 2));
	if (!op_Code)
	{
		malloc_failure();
		return;
	}
	while (i < c_length)
	{
		new_code[i] = op_Code[i];
		i++;
	}
	exit_str = to_string(error_code);
	if (!exit_str)
	{
		free(new_code);
		malloc_failure();
		return;
	}
	new_code[i++] = exit_str;
	new_code[i] = NULL;
	free(op_Code);
	op_Code = new_code;
}

/**
 * code_length - set length.
 *
 * Return: int.
 */
unsigned int code_length(void)
{
	unsigned int c_length = 0;

	while (op_Code[c_length])
		c_length++;
	return (c_length);
}
