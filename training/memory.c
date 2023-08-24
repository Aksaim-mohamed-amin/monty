#include "monty.h"

/**
 * _realloc - Realloc a new memory for a string and free the old memory.
 * @str: String to reallocate.
 * @size: New size for the string.
 *
 * Return: Pointer to the new string or NULL if it fails to allocate memory.
 */
char *_realloc(char *str, int size)
{
        int i;
        char *new_str;

        new_str = malloc(size);
        if (new_str == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }

        for (i = 0; str[i]; i++)
                new_str[i] = str[i];

        free(str);
        return new_str;
}
