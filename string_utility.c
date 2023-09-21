#include <stdlib.h>

char **strtow(char *str, char *delims);
int splitter(char ch, char *delims);
int w_length(char *str, char *delims);
int w_count(char *str, char *delims);
char *w_next(char *str, char *delims);

/**
 * strtow - split string to words
 * @str: string
 * @delims: delimitors
 * Return: array of  words
 */

char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = w_count(str, delims);


	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = w_length(str, delims);
		if (splitter(*str, delims))
		{
			str = w_next(str, delims);
		}
		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = w_next(str, delims);
		i++;
	}
	words[i] = NULL;
	return (words);
}

/**
 * splitter - delimitor char
 * @ch: character
 * @delims:  delimitors
 * Return: 1 /0
 */

int splitter(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * w_length -  word length
 * @str: string
 * @delims: delimitors
 * Return:  length
 */

int w_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (splitter(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && splitter(str[i], delims))
			break;
		i++;
	}
	return (wLen);
}

/**
 * w_count - words count
 * @str: string
 * @delims: delimitors
 * Return: words length
 */

int w_count(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (splitter(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * w_next - move next word
 * @str: string
 * @delims: delimitors
 * Return: next
 */

char *w_next(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (splitter(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
