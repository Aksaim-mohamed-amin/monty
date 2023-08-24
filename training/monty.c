#include "monty.h"

global_t glb;

/**
 * main - Monty byte code interpreter.
 * @ac: Arguments count.
 * @av: Argument vecteur.
 *
 * Return: 0 Success.
 */
int main(int ac, char **av)
{
	FILE *file;
	char *line;
	int rv;


	file = validate_input(ac, av[1]);

	init_glb(file);
	while ((line = _getline(file)) != NULL)
	{
                glb.command = strtok(line, " \t\n");

		if (glb.command && glb.command[0] != '#')
		{
			glb.value = strtok(NULL, " \t\n");

			rv = opcode();
			if (rv == -1)
			{
				fprintf(stderr, "L%d: ", glb.line_count);
				fprintf(stderr, "unknown instructions ");
				fprintf(stderr, "%s\n", glb.command);
				free_glb();
				exit(EXIT_FAILURE);
			}
			glb.line_count++;
		}
		free(line);
	}

	free_glb();
	return (0);
}
