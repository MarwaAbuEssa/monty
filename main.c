
#include "monty.h"

char **op_Code = NULL;
/**
 * main - the entry point
 * @argc:  arguments
 * @argv:  arguments
 * Return: (EXIT_SUCCESS) or (EXIT_FAILURE)
 */

int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_failure());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (f_open_failure(argv[1]));
	exit_code = run_monty(script_fd);
	fclose(script_fd);
	return (exit_code);
}
