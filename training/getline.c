#include "monty.h"

/**
 * _getline - Read one line at a time from a file.
 * @file: File to read from it.
 *
 * Return: Pointer to the line read, or NULL if it reach EOF.
 */
char *_getline(FILE *file)
{
	int c, index = 0, BUFF_SIZE = 100;
	char *line = NULL;
	char *tmp;

	line = malloc(BUFF_SIZE);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while ((c = fgetc(file)) != EOF && c != '\n')
	{
		if (index >= BUFF_SIZE - 1)
		{
			BUFF_SIZE *= 2;
			tmp = _realloc(line, BUFF_SIZE);
			if (tmp == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			line = tmp;
		}

		line[index++] = c;
	}

	if (index == 0 && c == EOF)
	{
		free(line);
		return (NULL);
	}

	line[index] = '\0';
	return line;
}
