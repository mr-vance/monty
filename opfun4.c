#include "monty.h"

/**
 * rotate_left - Rotate the stack to the left
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void rotate_left(stack_t **stack, unsigned int line_number) {
    stack_t *temp = *stack;
    (void)line_number;

    if (temp && temp->next) {
        while (temp->next != NULL) {
            stack_t *next_node = temp->next;
            temp->next = next_node->next;
            if (next_node->next)
                next_node->next->prev = temp;
            next_node->next = *stack;
            next_node->prev = NULL;
            (*stack)->prev = next_node;
            *stack = next_node;
        }
    }
}

/**
 * rotate_right - Rotate the stack to the right
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void rotate_right(stack_t **stack, unsigned int line_number) {
    stack_t *temp = *stack;
    (void)line_number;

    if (temp && temp->next) {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        while (temp != *stack) {
            stack_t *prev_node = temp->prev;
            temp->prev = prev_node->prev;
            if (prev_node->prev)
                prev_node->prev->next = temp;
            temp->next = *stack;
            temp->prev = NULL;
            (*stack)->prev = temp;
            *stack = temp;
            temp = prev_node;
        }
    }
}

/**
 * set_stack_mode - Set the mode to stack (LIFO)
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void set_stack_mode(stack_t **stack, unsigned int line_number) {
    (void)line_number;
    (void)stack;

    var.MODE = 0;
}

/**
 * set_queue_mode - Set the mode to queue (FIFO)
 * @stack: Double linked list representing the stack
 * @line_number: Line number in the file
 */
void set_queue_mode(stack_t **stack, unsigned int line_number) {
    (void)line_number;
    (void)stack;

    var.MODE = 1;
}
