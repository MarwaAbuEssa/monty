#ifndef __MONTY_H__
#define __MONTY_H__
#define  _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <string.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"


extern char **op_Code;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void free_stack(stack_t **stack);
int create(stack_t **stack);
int stack_Type(stack_t *stack);


int usage_failure(void);
int malloc_failure(void);
int file_failure(char *filename);
int unknown_failure(char *opcode, unsigned int line_number);
int int_failure(unsigned int line_number);
int pop_failure(unsigned int line_number);
int pint_failure(unsigned int line_number);
int stack_failure(unsigned int line_number, char *op);
int div_failure(unsigned int line_number);
int pchar_failure(unsigned int line_number, char *message);

void free_opcode(void);
unsigned int opcode_length(void);
int start(FILE *file_script);
void set_failure(int code);

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);


char **strtow(char *str, char *delims);
char *get_int(int n);




#endif 
