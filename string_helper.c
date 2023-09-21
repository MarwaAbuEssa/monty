
#include <stdlib.h>

char *to_string(int num);
unsigned int _abs(int);
int base_number(unsigned int num, unsigned int base);
void buff_size(unsigned int num, unsigned int base,
		char *buff, int buff_size);

/**
 * to_string - pointer
 * @num: number 
 *
 * Return: string or nll.
 */
char *to_string(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	length = base_number(temp, 10);

	if (num < 0 || num_l < 0)
		length++; 
	ret = malloc(length + 1); 
	if (!ret)
		return (NULL);

	buff_size(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - absolute value 
 * @i: integer t
 *
 * Return: absolute value
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * base_number - buffer length
 * @num: number
 * @base: base of number
 *
 * Return: integer 
 */
int base_number(unsigned int num, unsigned int base)
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
 * buff_size - fills buffer
 * @num: convert to string 
 * @base: base  number
 * @buff: buffer 
 * @buff_size: size of buffer
 */
void buff_size(unsigned int num, unsigned int base,
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

