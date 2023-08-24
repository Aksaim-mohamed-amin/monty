#ifndef MONTY_H
#define MONTY_H

/***** Libraries *****/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/***** Stuctures *****/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - Global structur to hold variavles during run time.
 * @file: Monty file descriptor.
 * @head: Head of the stack.
 * @mod: Mode to use (stack or queue).
 * @line_count: Current line in the monty file.
 * @command: The command extracted from the monty line.
 * @value: The value taken from the line.
 */
typedef struct global_s
{
	FILE *file;
	stack_t *head;
	int mode;
	unsigned int line_count;
	char *command;
	char *value;
} global_t;

extern global_t glb;


/***** Main Functions *****/
FILE *validate_input(int ac, char *file_name);
char *_getline(FILE *file);
int opcode(void);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/***** Help Functions *****/
void init_glb(FILE *file);
void free_glb(void);
char *_realloc(char *str, int size);


#endif /* MONTY_H */
