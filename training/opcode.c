#include "monty.h"

/**
 * opcode - Call the associated function for an opcode.
 *
 * Return: 0 if the command found, -1 if it is not found.
 */
int opcode(void)
{
        instruction_t op_list[] = {
                {"push", push}, {"pall", pall},
                {NULL, NULL}
        };
        int i, flag = 0;

	if (glb.command == NULL)
		return (-1);

        for (i = 0; op_list[i].opcode; i++)
        {
                if (strcmp(op_list[i].opcode, glb.command) == 0)
                {
                        op_list[i].f(&(glb.head), glb.line_count);
                        flag = 1;
                        break;
                }
        }

        if (flag)
                return (0);

        return (-1);
}
