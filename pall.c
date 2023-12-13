#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number being executed
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    /* Check if the stack exists */
    if (!stack)
    {
        fprintf(stderr, "L%u: Stack doesn't exist\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Print values on the stack */
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
