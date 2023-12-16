#include "monty.h"

/**
 * multiply_elements - Multiply the top two elements of the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void multiply_elements(stack_t **stack, unsigned int line_number) {
    if (!*stack || !(*stack)->next) {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        free_resources();
        exit(EXIT_FAILURE);
    }

    (*stack)->next->value *= (*stack)->value;
    pop(stack, line_number);
}

/**
 * modulo_elements - Compute the modulo of the top two elements of the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void modulo_elements(stack_t **stack, unsigned int line_number) {
    if (!*stack || !(*stack)->next) {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        free_resources();
        exit(EXIT_FAILURE);
    }

    if ((*stack)->value == 0) {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        free_resources();
        exit(EXIT_FAILURE);
    }

    (*stack)->next->value %= (*stack)->value;
    pop(stack, line_number);
}

/**
 * print_char - Print the character value at the top of the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void print_char(stack_t **stack, unsigned int line_number) {
    if (!stack || !*stack) {
        fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
        free_resources();
        exit(EXIT_FAILURE);
    }

    if (isascii((*stack)->value)) {
        printf("%c\n", (*stack)->value);
        return;
    }

    fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
    free_resources();
    exit(EXIT_FAILURE);
}

/**
 * print_string - Print the string starting from the top of the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void print_string(stack_t **stack, unsigned int line_number) {
    stack_t *tmp = *stack;
    (void)line_number;

    while (tmp && tmp->value != 0 && isascii(tmp->value)) {
        printf("%c", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}
