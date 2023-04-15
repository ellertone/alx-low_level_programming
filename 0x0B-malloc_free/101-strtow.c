#include "main.h"

/**
 * strtow - Split a string into words
 * @str: The string to be split
 *
 * Return: Pointer to an array of strings (words), or NULL on failure
 */
char **strtow(char *str)
{
	char **stray;
	int i = 0, j = 0, column = 0, len = 0, ch = 0;
	int row[10];

	if (str == NULL || *str == '\0')
		return (NULL);

	while (str[len++])
		if (str[len - 1] == ' ' && str[len] != ' ')
			column++;

	column++;

	stray = malloc(sizeof(char *) * column);
	if (stray == NULL)
		return (NULL);

	len = 0, i = 0;
	while (str[len++])
	{
		if (str[len - 1] != ' ' && str[len] != ' ')
			ch++;
		if (str[len - 1] == ' ' && str[len] != ' ')
		{
			row[i] = ch;
			stray[i] = malloc(sizeof(char) * (row[i] + 1));
			if (stray[i] == NULL)
			{
				for (; i >= 0; i--)
					free(stray[i]);
				free(stray);
				return (NULL);
			}
			ch = 0, i++;
		}
	}
	len = 0;
	while (str[len])
	{
		if (str[len] == ' ' && str[len + 1] != ' ')
		{
			j = 0;
			for (i = 0; i < row[len / 2]; i++)
				stray[len / 2][j++] = str[len++];
			stray[len / 2][j] = '\0';
		}
		else
			len++;
	}
	stray[column - 1] = NULL;
	return (stray);
}

