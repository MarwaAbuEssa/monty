#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int buffer_length(unsigned int num, unsigned int base);
void buffer_fill(unsigned int num, unsigned int base,
		       char *buff, int buff_size);

/**
 * get_int - convert int ot string
 * @num: number 
 * Return: string or null.
 */
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	length = buffer_length(temp, 10);

	if (num < 0 || num_l < 0)
		length++;
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);

	buffer_fill(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - absolute value
 * @i: integer
 * Return: integer abs 
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * buffer_length - buffer length
 * @num: number 
 * @base: base of number
 * Return: integer
 */
int buffer_length(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * buffer_fill - fills buffer
 * @num: number
 * @base: base of number
 * @buff: buffer
 * @buff_size: size of buffer
 */
void buffer_fill(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[i] = rem + 87;
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
