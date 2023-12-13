#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number being executed
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *token;
    int value;

    /* Check if the stack and argument exist */
    if (!stack)
    {
        fprintf(stderr, "L%u: Stack doesn't exist\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Read the next token (which should be the integer to push) */
    token = strtok(NULL, " \n\t");

    /* Check if the token exists */
    if (!token)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Check if the token is a valid integer */
    if (!is_integer(token))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Convert token to an integer */
    value = atoi(token);

    /* Create a new stack node */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    /* Assign value to the new node */
    new_node->n = value;
    new_node->prev = NULL;

    /* If stack is empty, new node is both head and tail */
    if (!*stack)
    {
        new_node->next = NULL;
        *stack = new_node;
    }
    else
    {
        /* Add the new node to the top of the stack */
        new_node->next = *stack;
        (*stack)->prev = new_node;
        *stack = new_node;
    }
}
