#include "monty.h"

/**
 * swap_elements - Swap the top two elements of the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void swap_elements(stack_t **stack, unsigned int line_number) {
    if (!*stack || !(*stack)->next) {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        free_resources();
        exit(EXIT_FAILURE);
    }

    int temp = (*stack)->value;
    (*stack)->value = (*stack)->next->value;
    (*stack)->next->value = temp;
}

/**
 * add_elements - Add the top two elements of the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void add_elements(stack_t **stack, unsigned int line_number) {
    if (!*stack || !(*stack)->next) {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        free_resources();
        exit(EXIT_FAILURE);
    }

    (*stack)->next->value += (*stack)->value;
    pop(stack, line_number);
}

/**
 * subtract_elements - Subtract the top two elements of the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void subtract_elements(stack_t **stack, unsigned int line_number) {
    if (!*stack || !(*stack)->next) {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        free_resources();
        exit(EXIT_FAILURE);
    }

    (*stack)->next->value -= (*stack)->value;
    pop(stack, line_number);
}

/**
 * divide_elements - Divide the top two elements of the stack
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void divide_elements(stack_t **stack, unsigned int line_number) {
    if (!*stack || !(*stack)->next) {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        free_resources();
        exit(EXIT_FAILURE);
    }

    if ((*stack)->value == 0) {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        free_resources();
        exit(EXIT_FAILURE);
    }

    (*stack)->next->value /= (*stack)->value;
    pop(stack, line_number);
}
