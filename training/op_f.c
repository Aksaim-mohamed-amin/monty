#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	(void)line_number;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }

        new_node->n = atoi(glb.value);
        new_node->prev = NULL;

        if (*stack == NULL)
        {
                new_node->next = NULL;
        }
        else
        {
                new_node->next = *stack;
                (*stack)->prev = new_node;
        }

        *stack = new_node;
}

/**
 * pall - Prints all the elements in the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
        (void)line_number;

	current = *stack;

        while (current != NULL)
        {
                printf("%d\n", current->n);
                current = current->next;
        }
}
