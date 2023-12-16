#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#define Buffsize 30

typedef struct stack_s
{
    int value;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*handler)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct global_vars
{
    FILE *file;
    char *buffer;
    size_t tmp;
    instruction_t *instruction_set;
    stack_t *stack_head;
    unsigned int line_num;
    int mode;
} variables;

extern variables vars;

/* ================================== */
/* Functions in man_file.c */
/* ================================== */
int initialize_vars(variables *vars);
instruction_t *create_instructions();
int execute_function(variables *vars, char *opcode);
void free_resources(void);
int is_digit(char *string);

/* ================================== */
/* Functions in op_functions.c */
/* ================================== */
void print_all(stack_t **stack, unsigned int line_number);
void push_element(stack_t **stack, unsigned int line_number);
void print_int(stack_t **stack, unsigned int line_number);
void remove_element(stack_t **stack, unsigned int line_number);

/* ================================== */
/* Functions in op_functions_2.c */
/* ================================== */
void swap_elements(stack_t **stack, unsigned int line_number);
void add_elements(stack_t **stack, unsigned int line_number);
void subtract_elements(stack_t **stack, unsigned int line_number);
void divide_elements(stack_t **stack, unsigned int line_number);

/* ================================== */
/* Functions in op_functions_3.c */
/* ================================== */
void multiply_elements(stack_t **stack, unsigned int line_number);
void modulo_elements(stack_t **stack, unsigned int line_number);
void print_char(stack_t **stack, unsigned int line_number);
void print_string(stack_t **stack, unsigned int line_number);

/* ================================== */
/* Functions in op_functions_4.c */
/* ================================== */
void rotate_left(stack_t **stack, unsigned int line_number);
void rotate_right(stack_t **stack, unsigned int line_number);
void set_stack_mode(stack_t **stack, unsigned int line_number);
void set_queue_mode(stack_t **stack, unsigned int line_number);

#endif
