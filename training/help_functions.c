#include "monty.h"

/**
 * validate_input - Validat if the user input the correct number of args.
 *                  and check if the file can be open.
 *                  if error happen exit with an error.
 * @ac: Number of arguments.
 * @file_name: File to open.
 *
 * Return: File descriptor.
 */
FILE *validate_input(int ac, char *file_name)
{
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(file_name, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}

	return (file);
}

/**
 * init_glb - Initialize Global variables.
 * @file: File descriptor.
 */
void init_glb(FILE *file)
{
	glb.file = file;
	glb.head = NULL;
	glb.mode = 1;
	glb.line_count = 1;
	glb.command = NULL;
	glb.value = NULL;
}

/**
 * free_glb - Free the global variables.
 */
void free_glb(void)
{
        if (glb.head != NULL)
        {
                while (glb.head != NULL)
                {
                        stack_t *temp = glb.head;
                        glb.head = glb.head->next;
                        free(temp);
                }
        }

        if (glb.command != NULL)
                free(glb.command);

        fclose(glb.file);
}
