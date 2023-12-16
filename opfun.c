#include "monty.h"

/**
 * print_stack - Print elements in the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void print_stack(stack_t **stack, unsigned int line_number) {
    stack_t *current = *stack;
    (void)line_number;

    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

/**
 * add_to_stack - Add a new value to the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void add_to_stack(stack_t **stack, unsigned int line_number) {
    char *num_str = strtok(NULL, " \r\t\n");
    if (num_str == NULL || (_isdigit(num_str) != 0 && num_str[0] != '-')) {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free_resources();
        exit(EXIT_FAILURE);
    }

    int num = atoi(num_str);
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        free_resources();
        exit(EXIT_FAILURE);
    }

    new_node->value = num;
    new_node->next = *stack;
    new_node->prev = NULL;

    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

/**
 * print_top - Print the top element of the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void print_top(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL) {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        free_resources();
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->value);
}

/**
 * remove_top - Remove the top element from the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void remove_top(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL) {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        free_resources();
        exit(EXIT_FAILURE);
    }

    stack_t *temp = *stack;
    *stack = (*stack)->next;
    
    if (*stack != NULL) {
        (*stack)->prev = NULL;
    }

    free(temp);
}
